#include <stdio.h>

int main()
{
	int a = 20, b = 10;

	if (a > 10)
	{
		if (b >=0)
		{
			b = 1;
		}
		else
		{
			b = -1;
		}
	}

	printf("a : %d\nb : %d", a, b);

	return 0;
}