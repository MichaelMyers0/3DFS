#include "fs_user_dump.h"
#include "constv.h"
int main()
{
	fs_user_dump fs(".", space::start_port_number);
	fs.start();
	fs_user_dump fs1("./d", space::start_port_number + 1);
	fs1.start();
//	fs.connect_to_abars(space::abars_port_number);
	exit(0);
}
