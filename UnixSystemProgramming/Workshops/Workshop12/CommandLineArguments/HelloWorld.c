/*
 ============================================================================
 Name        : HelloWorld.c
 Author      : Jigar Pandya - jigarpandya.ce@ddu.ac.in
 Version     : 1.0.0
 Copyright   : None
 Description : Hello World in C, Ansi-style.
 Purpose		 : To explain command line arguments, exit status using echo $? command and makefile.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	if(argc == 1)  //Only the executable filename
	{
		printf("\nCommand line arg#%d and data %s",0,argv[0]);
		return EXIT_FAILURE;
	}
	else
	{
		for (int i=1;i<argc; i++)
		{
			printf("\nCommand line arg#%d and data %s",i,argv[i]);
		}
		return EXIT_SUCCESS;
	}
}







