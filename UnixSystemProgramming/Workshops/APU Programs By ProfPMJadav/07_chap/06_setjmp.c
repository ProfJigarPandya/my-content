#include "../pmj.h"

/* setjmp and longjmp => Nonlocal goto */

jmp_buf jmpbuf;

void first();
void second();
void third();

int main()
{
	int val;

	/* uses jmpbuf to remember current position and returns 0 */
	val = setjmp(jmpbuf);

	if (val != 0) {
		printf("The return value is %d\n", val);
		exit(EXIT_FAILURE);
	}	

	first();
	printf("I am the end of the main() function\n");

}
void first()
{
	char ans;

	printf("I am first!\n");
	printf("Do you want to continue? ");
	scanf("%c%*c", &ans);
	if ( ans != 'y') /* On error goto main() and rewind the stack frame */
		longjmp(jmpbuf, 1); /* Go back to place jmpbuf is pointing to and return 1  */
	second();
	printf("I am the end of the first() \n");
}
void second()
{
	char ans;

	printf("I am second!\n");
	printf("Do you want to continue? ");
	scanf("%c%*c", &ans);
	if ( ans != 'y') /* On error goto main() and rewind the stack frame */
		longjmp(jmpbuf, 2); /* Go back to place jmpbuf is pointing to and return 2  */
	third();
	printf("I am the end of the second()\n");
}
void third()
{
	printf("I am third!\n");
}

/*
pmj@PMJLaptop:~/prg/07_chap$ ./a.out
I am first!
Do you want to continue? y
I am second!
Do you want to continue? y
I am third!

pmj@PMJLaptop:~/prg/07_chap$ ./a.out
I am first!
Do you want to continue? y
I am second!
Do you want to continue? n
The return value is 2

pmj@PMJLaptop:~/prg/07_chap$ ./a.out
I am first!
Do you want to continue? n
The return value is 1
*/

