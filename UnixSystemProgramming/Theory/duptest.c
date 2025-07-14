#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
  int fd1, fd2;
  char buf[20];
  int n;

  fd1 = open("test.txt",O_RDWR);
  fd2 = dup(fd1);

  n = read(fd1, buf, sizeof(buf));
  write(1, buf, n);

  n = read(fd2, buf, sizeof(buf));
  write(1, buf, n);

  
  n = read(fd1, buf, sizeof(buf));
  write(1, buf, n);

  n = read(fd2, buf, sizeof(buf));
  write(1, buf, n);

  return 0;
}

