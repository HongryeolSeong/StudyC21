#include <stdio.h>

int swap1(int a, int b);
int swap2(int a, int b);

int main()
{
	int a = 10, b = 20;
	int c, d;
	int temp;

	printf("¹Ù²î±âÀü a, b : %d, %d\n", a, b);

	c = swap1(a, b);
	d = swap2(a, b);

	printf("¹Ù²ïÈÄ a, b : %d, %d\n", c, d);

	return 0;
}

int swap1(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

	return a;
}

int swap2(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

	return b;
}