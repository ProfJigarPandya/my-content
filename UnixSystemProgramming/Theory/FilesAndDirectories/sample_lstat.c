//man 2 lstat
//man 7 inode

/*

The file type and mode
       The stat.st_mode field (for statx(2), the statx.stx_mode field) contains the file type and mode.

 The following mask values are defined for the file type:
           S_IFMT     0170000   bit mask for the file type bit field

           S_IFSOCK   0140000   socket
           S_IFLNK    0120000   symbolic link
           S_IFREG    0100000   regular file
           S_IFBLK    0060000   block device
           S_IFDIR    0040000   directory
           S_IFCHR    0020000   character device
           S_IFIFO    0010000   FIFO


     S_ISREG(m)  is it a regular file?

           S_ISDIR(m)  directory?

           S_ISCHR(m)  character device?

           S_ISBLK(m)  block device?

           S_ISFIFO(m) FIFO (named pipe)?

           S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)

           S_ISSOCK(m) socket?  (Not in POSIX.1-1996.)





*/
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  struct stat sb;

  if (argc != 2)
    {
      fprintf (stderr, "Usage: %s <pathname>\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  if (stat (argv[1], &sb) == -1)
    {
      perror ("stat");
      exit (EXIT_FAILURE);
    }

  printf ("File type:                ");

  switch (sb.st_mode & S_IFMT)
    {
    case S_IFBLK:
      printf ("block device\n");
      break;
    case S_IFCHR:
      printf ("character device\n");
      break;
    case S_IFDIR:
      printf ("directory\n");
      break;
    case S_IFIFO:
      printf ("FIFO/pipe\n");
      break;
    case S_IFLNK:
      printf ("symlink\n");
      break;
    case S_IFREG:
      printf ("regular file\n");
      break;
    case S_IFSOCK:
      printf ("socket\n");
      break;
    default:
      printf ("unknown?\n");
      break;
    }

  printf ("I-node number:            %ld\n", (long) sb.st_ino);

  printf ("Mode:                     %lo (octal)\n",
	  (unsigned long) sb.st_mode);

  printf ("Link count:               %ld\n", (long) sb.st_nlink);
  printf ("Ownership:                UID=%ld   GID=%ld\n",
	  (long) sb.st_uid, (long) sb.st_gid);

  printf ("Preferred I/O block size: %ld bytes\n", (long) sb.st_blksize);
  printf ("File size:                %lld bytes\n", (long long) sb.st_size);
  printf ("Blocks allocated:         %lld\n", (long long) sb.st_blocks);

  printf ("Last status change:       %s", ctime (&sb.st_ctime));
  printf ("Last file access:         %s", ctime (&sb.st_atime));
  printf ("Last file modification:   %s", ctime (&sb.st_mtime));

  exit (EXIT_SUCCESS);
}
