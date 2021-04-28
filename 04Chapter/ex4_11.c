#include <stdio.h>

int main()
{
	int a = 10, b = 20;
	int res;

	res = (++a, ++b); // 11 된후 21로 다시 대입 됨

	printf("a:%d, b:%d\n", a, b);
	printf("res:%d\n", res);

	return 0;
}