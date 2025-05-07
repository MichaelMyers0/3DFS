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
	enum {back_slash = '/'};
	sockets s;
	std::stack<const char*> stack;
	std::vector<const char*> files;
	char buf[buf_cap];
	void path_builder(const char* start, char* path, char* dir_name);
public:
	fs_user_dump() = default;
	fs_user_dump(const char* path, int port);
	void start(const char* path=NULL);
	void connect_to_abars(int port);	
	~fs_user_dump();
};
#endif
