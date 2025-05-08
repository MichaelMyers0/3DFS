#ifndef ABARS_H
#define ABARS_H
#include "net.h"
#include "constv.h"
#include <sys/stat.h>
class abars
{
	sockets s;
	static int server_id;
public:	
	abars();
	void start();
	~abars();
};
#endif
