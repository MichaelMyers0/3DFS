#include "abars.h"

void abars::create_dir(const char* dir_name)
{
        errno = 0;
        auto res = mkdir(dir_name, 0777);
        if (res == -1)
        {
                perror("void abars::create_dir()\n");
                exit(1);
        }
}

abars::abars()
{
	create_dir("./abras_fs");
	s.creat_socket(AF_INET6, SOCK_STREAM);
	s.bind_socket(space::abars_port_number);
	s.listenn(space::nums_of_logs);
}

void abars::start()
{
	auto sfd = -1, count = 0, len = 0;
	pid_t child;
	for (;;)
	{
		s.acceptt(sfd);
		s.read_msg(sfd, sbuf);
		len = strlen(sbuf);
		if (len)
		{
			*(sbuf + len) = 0;
			printf("%s\n", sbuf);
			*sbuf = 0;
		}
		if (!len)
			break;
	}
}

abars::~abars()
{
	s.reuse_port();
	s.close_socket();
}
