#include "fs_user_dump.h"

int main()
{
	fs_user_dump fs(".", start_port_number);
//	fs.init(".");
	fs.start(NULL);
	exit(0);
}
