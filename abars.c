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

void abars::create_dir_for_a_user(const char* fname)
{
	strcpy(dir_name, "abars_fs");	
	auto len = strlen(dir_name);
	*(dir_name + len) = back_slash[0];
	strcpy(dir_name + len + 1, fname);
	len = strlen(dir_name);
	*(dir_name + len) = 0;
	create_dir(dir_name);
}

abars::abars()
{
	create_dir("./abars_fs");
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
		s.read_msg(sfd, sbuf);
		len = strlen(sbuf);
		if (len && !is_flag_set)
		{
			create_dir_for_a_user(sbuf);
			is_flag_set = 1;
			continue;
		}
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
