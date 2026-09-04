#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 struct stat sb;
 int retv = stat(argv[1],&sb);
 if(retv==-1)
 {
  perror("stat error : ");
  exit(1);
 }
 if(sb.st_mode & S_IRUSR)
 {
  printf("\n S_IRUSR File can be read by owner");
 }
else
{
  printf("\n S_IRUSR File can NOT be read by owner");
}

 if(sb.st_mode & S_IWUSR)
 {
  printf("\n S_IWUSR File can be write by owner");
 }
else
{
  printf("\n S_IWUSR File can NOT be write by owner");
}


 if(sb.st_mode & S_IXUSR)
 {
  printf("\n S_IXUSR File can be execute by owner");
 }
else
{
  printf("\n S_IXUSR File can NOT be execute by owner");
}

 

 if(sb.st_mode & S_IRGRP)
 {
  printf("\n S_IRGRP File can be read by group");
 }
else
{
  printf("\n S_IRGRP File can NOT be read by group");
}

 if(sb.st_mode & S_IWGRP)
 {
  printf("\n S_IWGRP File can be write by group");
 }
else
{
  printf("\n S_IWGRP File can NOT be write by group");
}


 if(sb.st_mode & S_IXGRP)
 {
  printf("\n S_IXGRP File can be execute by group");
 }
else
{
  printf("\n S_IXGRP File can NOT be execute by group");
}


 if(sb.st_mode & S_IROTH)
 {
  printf("\n S_IROTH File can be read by others");
 }
else
{
  printf("\n S_IROTH File can NOT be read by others");
}

 if(sb.st_mode & S_IWOTH)
 {
  printf("\n S_IWOTH File can be write by others");
 }
else
{
  printf("\n S_IWOTH File can NOT be write by others");
}


 if(sb.st_mode & S_IXOTH)
 {
  printf("\n S_IXOTH File can be execute by others");
 }
else
{
  printf("\n S_IXOTH File can NOT be execute by others");
}

 
 return 0;
}
