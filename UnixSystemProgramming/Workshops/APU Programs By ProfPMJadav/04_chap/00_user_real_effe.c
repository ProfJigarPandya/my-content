#include "../pmj.h"

int main()
{
	int fd, n, offset;
	char buf[6];
	int uid, euid;

	uid  = getuid();
	euid = geteuid();

	printf("Real      User id: %d\n", uid);
	printf("Effective User id: %d\n", euid);
	
	if ( (fd=open("pwd.txt",O_RDONLY)) < 0 )
		err_quit("open('pwd.txt')");

	switch(uid) {
		case 1000:	offset = 4; break;
		case 1001:	offset = 15; break;
		case 1002:	offset = 26; break;
	}
	lseek(fd, offset, SEEK_SET);
	
	n = read(fd, buf, sizeof(buf));

	write(STDOUT_FILENO, buf, n);
	printf("\n");
	
	close(fd);
	exit(0);
}

