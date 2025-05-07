#include "fs_user_dump.h"
void fs_user_dump::start(const char* path)
{
	struct dirent* ent;
	errno = 0;
	auto dirp = opendir(path);
	if (!dirp)
	{
		perror("void fs_user_dump::start(path)->opendir()\n");
		exit(1);
	}
	while ((ent = readdir(dirp)))
	{
		if (0 == strcmp(ent->d_name, ".") || 0 == strcmp(ent->d_name, ".."))
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
				strcpy(buf, ent->d_name);
				*(buf + len) = 0;
				stack.push(buf);
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
}
