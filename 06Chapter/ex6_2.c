#include <stdio.h>

int main()
{
	int a = 1;
	int i;

	for (i = 0; i < 3; i++) 
	{
		a = a * 2;
		/*
		i=0 a=2
		i=1 a=4
		i=2 a=8
		*/
	}
	printf("a : %d\n", a);

	return 0;
	
	// for( : : ) for 무한반복문
}