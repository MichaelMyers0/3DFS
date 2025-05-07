#include "fs_user_dump.h"

void fs_user_dump::path_builder(const char* start, char* path, char* dir_name)
{
	auto len = 0;
	strcpy(path, start);
	len = strlen(path);
	*(path + len) = back_slash;
	strcpy(path + len + 1, dir_name);
	len = strlen(path);
	*(path + len) = 0;
}

void fs_user_dump::delete_spaces(char* string)
{
	while (*string)
	{
		if (*string == ' ')
			*string = '_';
		string++;
	}	
}

fs_user_dump::fs_user_dump(const char* path, int port)
{
	stack.push(path);
	s.creat_socket(AF_INET6, SOCK_STREAM);
	s.bind_socket(port);
}

void fs_user_dump::start(const char* path, const char* date)
{
	struct dirent* ent;
	struct stat sbuf;
	buffer b;
	char* p;
	auto res = 0, len = 0;
	errno = 0;
	auto dirp = opendir(stack.top());
	if (!dirp)
	{
		perror("void fs_user_dump::start(path)->opendir()\n");
		exit(1);
	}
	while ((ent = readdir(dirp)))
	{
		if (0 == strcmp(ent->d_name, ".") || 0 == strcmp(ent->d_name, "..") || 0 == strcmp(ent->d_name, ".git"))
			continue;
		switch (ent->d_type)
		{
			case DT_REG :
				errno = 0;
				res = stat(ent->d_name, &sbuf);
				path_builder(stack.top(), b.s, ent->d_name);
				len = strlen(b.s);
				*(b.s + len) = '_';
				p = ctime(&(sbuf.st_mtim.tv_sec));
				if (p)
					strcat(b.s, ctime(&(sbuf.st_mtim.tv_sec)));
				delete_spaces(b.s);
				len = strlen(b.s);
				*(b.s + len) = 0;
				files.push_back(b);
				break;
			case DT_DIR :
				len = strlen(ent->d_name);
				if (len >= buf_cap)
					break;
				path_builder(stack.top(), buf, ent->d_name);
				stack.push(buf);
				start(stack.top());
				*buf = 0;
				break;
		}
	}
	errno = 0;
	res = closedir(dirp);
	if (res == -1)
	{
		perror("void fs_user_dump::start(path)->closedir()\n");
		exit(2);
	}
	stack.pop();
}

void fs_user_dump::connect_to_abars(int port)
{
	s.connectt(port);
}

fs_user_dump::~fs_user_dump()
{
	s.reuse_port();
	s.close_socket();
}
