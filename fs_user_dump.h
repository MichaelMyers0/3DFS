#ifndef FS_USER_DUMP_H
#define FS_USER_DUMP_H
#include "net.h"
#include <sys/types.h>
#include <dirent.h>
#include <stack>
#include <vector>
class fs_user_dump
{
	enum {buf_cap = 1024};
	sockets s;
	std::stack<const char*> stack;
	std::vector<const char*> files;
	char buf[buf_cap];
public:
	void start(const char* path);	
};
#endif
