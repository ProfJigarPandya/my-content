#Just compile and do not link load using -c option. A c library file without main function.
rm *.o
gcc -Wall -c check.c -o check.o
gcc -Wall -c daemonize.c -o daemonize.o
gcc -Wall daemonize.o check.o echodaemon.c -o echodaemon.o
ls *.o
