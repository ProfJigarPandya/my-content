#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
  int fd[2];

  pipe(fd);

  close(0);
  dup(fd[0]);

  execlp("sort","sort",NULL);
}

