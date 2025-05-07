#include "net.h"

void sockets::creat_socket(int domain, int type)
{
	errno = 0;
	fd = socket(domain, type, 0);
	if (fd == -1)
	{
		perror("creat_socket()\n");
		exit(1);
	}
}

void sockets::addr_init(sockaddr_in6& s, int port)
{
	s.sin6_family = AF_INET6;
	s.sin6_addr = in6addr_any;
	s.sin6_port = htons(port);
}

void sockets::bind_socket(int port)
{
	addr_init(s, port);
	auto slen = sizeof(s);
	errno = 0;
	auto res = bind(fd, (const struct sockaddr*)&s, slen);
	if (res == -1)
	{
		perror("bind_socket()\n");
		exit(2);
	}
}

void sockets::listenn(int log)
{
	errno = 0;
	auto res = listen(fd, log);
	if (res == -1)
	{
		perror("listenn()\n");
		exit(3);
	}
}

void sockets::connectt(int port)
{
	struct sockaddr_in6 ss;
	addr_init(ss, port);
	auto slen = sizeof(ss);
	auto res = connect(fd, (const struct sockaddr*)&ss, slen);
	if (res == -1)
	{
		perror("connect()\n");
		exit(4);
	}
}

void sockets::acceptt(int& sfd)
{
	errno = 0;
	sfd = accept(fd, NULL, NULL);
	if (sfd == -1)
	{
		perror("acceptt()\n");
		exit(5);
	}
}

void sockets::send_msg(const char* msg)
{
	auto len = strlen(msg);
	write(fd, msg, len);
}

void sockets::send_msg(int sfd, const char* msg)
{
	auto len = strlen(msg);
	write(sfd, msg, len);
}

void sockets::read_msg(char* msg)
{
	errno = 0;
	auto cnt = read(fd, msg, msg_len);
	if (cnt == -1)
	{
		perror("read_msg(char* msg)\n");
		exit(6);
	}
	*(msg + cnt) = 0;
}

void sockets::read_msg(int sfd, char* msg)
{
	errno = 0;
	auto cnt = read(sfd, msg, msg_len);
	if (cnt == -1)
	{
		perror("read_msg(int sfd, char* msg\n)");
		exit(7);
	}
	*(msg + cnt) = 0;
}

void sockets::reuse_port()
{
	auto n = 0;
	errno = 0;
	auto res = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(n));
	if (res == -1)
	{
		perror("reuse_port()\n");
		exit(8);
	}
}

void sockets::close_socket()
{
	errno = 0;
	auto res = close(fd);
	if (res == -1)
	{
		perror("close_socket()\n");
		exit(9);
	}
}

sockets::~sockets()
{
        auto n = 0;
	printf("sockets::~sockets()\n");
        errno = 0;
        auto res = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(n));
        if (res == -1)
        {
                perror("reuse_port()\n");
                exit(10);
        }	
}
