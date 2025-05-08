#include "fs_user_dump.h"
#include "constv.h"
#include "abars.h"
int main()
{
	fs_user_dump fs("lan1", ".", space::start_port_number);
	fs.start();
	fs_user_dump fs1("lan2", "./d", space::start_port_number + 1);
	fs1.start();
	abars a;
//	fs.connect_to_abars(space::abars_port_number);
	exit(0);
}
