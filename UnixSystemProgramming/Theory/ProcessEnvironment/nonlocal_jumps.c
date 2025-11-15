/* setjmp and longjmp => Nonlocal goto */

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jmpbuf;

void level1();
void level2();
void level3();

int main()
{
	int val;

	/* uses jmpbuf to remember current position and returns 0 */
	val = setjmp(jmpbuf);

	if (val != 0) {
		printf("The return value is %d\n", val);
		exit(EXIT_FAILURE);
	}	

	level1();
	printf("I am the end of the main() function\n");

}
void level1()
{
	char ans;

	printf("I am level1!\n");
	printf("Do you want to continue? ");
	scanf("%c%*c", &ans);
	if ( ans != 'y') /* On error goto main() and rewind the stack frame */
		longjmp(jmpbuf, 1); /* Go back to place jmpbuf is pointing to and return 1  */
	level2();
	printf("I am the end of the level1() \n");
}
void level2()
{
	char ans;

	printf("I am level2!\n");
	printf("Do you want to continue? ");
	scanf("%c%*c", &ans);
	if ( ans != 'y') /* On error goto main() and rewind the stack frame */
		longjmp(jmpbuf, 2); /* Go back to place jmpbuf is pointing to and return 2  */
	level3();
	printf("I am the end of the level2()\n");
}
void level3()
{
	printf("I am level3!\n");
}

