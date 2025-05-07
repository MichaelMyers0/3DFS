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

void fs_user_dump::dump()
{
	while (stack.top())
	{
		printf("%s\n", stack.top());
		stack.pop();
	}
}

void fs_user_dump::init(const char* path)
{
	stack.push(path);
}

void fs_user_dump::start(const char* path)
{
	struct dirent* ent;
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
				files.push_back(ent->d_name);
				break;
			case DT_DIR :
				auto len = strlen(ent->d_name);
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
	auto res = closedir(dirp);
	if (res == -1)
	{
		perror("void fs_user_dump::start(path)->closedir()\n");
		exit(2);
	}
	dump();
}
