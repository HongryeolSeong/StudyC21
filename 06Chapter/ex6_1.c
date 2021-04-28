#include <stdio.h>

int main()
{
	int a = 1;

	while (a < 10) // 1 2 4 6 8
	{
		a = a * 2;
	}
	printf("a : %d\n", a);

	return 0;
}