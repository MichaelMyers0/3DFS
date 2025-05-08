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
	s.bind_socket(space::abars_port_number + 1);
	s.listenn(space::nums_of_logs);
}

void abars::start()
{
	auto count = 0, len = 0, flags = 0;
	int sfd;
	bool is_flag_set = false;
	pid_t child;
	s.acceptt(sfd);
	for (;;)
	{
//		s.acceptt(sfd);
#if 0
		if (!is_flag_set)
		{
			flags = fcntl(sfd, F_GETFL);
			fcntl(sfd, F_SETFL, flags | O_NONBLOCK);
			is_flag_set = true;
		}
#endif		
		s.read_msg(sfd, sbuf);
		len = strlen(sbuf);
		if (len)
		{
			*(sbuf + len) = 0;
			printf("%s\n", sbuf);
			*sbuf = 0;
		}
		if (len == 0)
			break;
	}
}

abars::~abars()
{
	s.reuse_port();
	s.close_socket();
}
