#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main()
{
  int fd;
  char str[] = "hello";

  fd = open("test.txt",O_RDWR | O_CREAT, 0644);
  //close(1);
  //dup(fd);
  dup2(fd, 1);
  write(1, str, strlen(str));
  close(fd);
}

