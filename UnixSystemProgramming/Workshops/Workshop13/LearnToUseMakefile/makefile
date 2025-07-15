#Compiling with -c option generates independant binary object file which can be shared with others.
all: runme

runme : DriverMatrix.o AddMatrices.o DisplayMatrix.o
	 gcc -o runme Addmatrices.o DisplayMatrix.o DriverMatrix.o


DriverMatrix.o : DriverMatrix.c Matrix.h
	gcc -Wall -c DriverMatrix.c -o DriverMatrix.o

AddMatrices.o : AddMatrices.c 
	gcc -c AddMatrices.c -o AddMatrices.o 

DisplayMatrix.o : DisplayMatrix.c
	gcc -c DisplayMatrix.c -o DisplayMatrix.o

.PHONY : clean
clean: 
	rm -rf *.o
	rm -rf runme

