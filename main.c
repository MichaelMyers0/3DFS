#include "fs_user_dump.h"
int main()
{
	fs_user_dump fs("lan1", "./d", space::start_port_number + 1);
	fs.start();
	fs.connect_to_abars(space::abars_port_number);
	fs.send_to_abars();
	exit(0);
}
