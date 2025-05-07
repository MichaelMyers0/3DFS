#include "fs_user_dump.h"
#include "constv.h"
int main()
{
	fs_user_dump fs(".", space::start_port_number);
	fs.start(NULL);
	fs.connect_to_abars(space::abars_port_number);
	exit(0);
}
