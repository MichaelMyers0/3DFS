#include "fs_user_dump.h"
#if 0
The program works fine. The only problem is when tou send to the server, idont know why
but it sends everything in one line
you need to add fcntl.h 
and use SET_FLAGS && GET_FLAGS
#endif
int main()
{
	fs_user_dump fs("lan1", "./d", space::start_port_number + 1);
	fs.start();
	fs.connect_to_abars(space::abars_port_number + 1);
	fs.send_to_abars();
	exit(0);
}
