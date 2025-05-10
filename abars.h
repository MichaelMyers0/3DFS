#ifndef ABARS_H
#define ABARS_H
#include "net.h"
#include "constv.h"
#include <sys/stat.h>
#include <fcntl.h>
class abars
{
	enum {buf_cap = 512};
	const char* back_slash = "/";
	sockets s;
	static int server_id;
	char sbuf[buf_cap];
	char dir_name[buf_cap];
	void create_dir(const char* dir_name);
	void create_dir_for_a_user(const char* fname);
public:	
	abars();
	void start();
	~abars();
};
#endif
