#ifndef ABARS_H
#define ABARS_H
#include "net.h"
#include "constv.h"
#include <sys/stat.h>
#include <fcntl.h>
class abars
{
	enum {buf_cap = 512};
	sockets s;
	static int server_id;
	char sbuf[buf_cap];
	char dir_name[buf_cap];
	void create_dir(const char* dir_name);
public:	
	abars();
	void start();
	~abars();
};
#endif
