#include "abars.h"

abars::abars()
{
	errno = 0;
	auto res = mkdir("./abars_fs", 0777);
	if (res == -1)
	{
		perror("abars::abars()\n");
		exit(1);
	}
	s.creat_socket(AF_INET6, SOCK_STREAM);
	s.bind_socket(space::abars_port_number);
	s.listenn(space::nums_of_logs);
}

void abars::start()
{
	auto sfd = -1;
	for (;;)
	{
		s.acceptt(sfd);
	}
}

abars::~abars()
{
	s.reuse_port();
	s.close_socket();
}
