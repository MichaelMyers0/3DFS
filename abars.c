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
}
