#ifndef NET_H
#define NET_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <cstring>
class sockets
{
	enum {msg_len = 512};
	int fd;
	struct sockaddr_in6 s;
	const struct in6_addr in6addr_any = IN6ADDR_ANY_INIT;
	void addr_init(sockaddr_in6& s, int port);
public:	
	sockets() = default;
	void creat_socket(int domain, int type);
	void bind_socket(int port);
	void listenn(int log);
	void connectt(int port);
	void acceptt(int& sfd);
	void send_msg(const char* msg, int& cnt);
	void send_msg(int sfd, const char* msg);
	void read_msg(char* msg);
	void read_msg(int sfd, char* msg);
	void reuse_port();
	void close_socket();
	~sockets();
};
#endif
