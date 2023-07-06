gcc -Wall -g -c date_clnt.c 
gcc -Wall -g -c date_client.c 
gcc -g -o date_client date_clnt.o  date_client.o
gcc -Wall -g -c date_svc.c 
gcc -Wall -g -c date_server.c 
gcc -g -o date_server date_svc.o date_server.o

