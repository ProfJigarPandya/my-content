#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int fd[2];

  pipe(fd);

  close(0);
  dup(fd[0]);

  execlp("sort","sort",NULL);

  return (0);
}

