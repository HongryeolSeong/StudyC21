#include <stdio.h>

int main()
{
	int a = 10, b = 20;
	int res;

	res = (++a, ++b); // 11 ���� 21�� �ٽ� ���� ��

	printf("a:%d, b:%d\n", a, b);
	printf("res:%d\n", res);

	return 0;
}