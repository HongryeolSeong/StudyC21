#include <stdio.h>

int main()
{
	int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a ^ b);
	printf("a | b : %d\n", a | b);
	printf("~a : %d\n", ~a);
	printf("a << 1 : %d\n", a << 1); // 맨 오른쪽 값은 무조건 0이 채워짐
	printf("a >> 2 : %d\n", a >> 2); // 맨 왼쪽 값은 부호비트에 따른 값이 채워짐

	char ch = 128; // 0b 1000 0000
	unsigned char ch1 = 128;
	printf("ch >> 1 : %d\n", ch >> 1); // 0b 1100 0000
	printf("ch >> 1 : %d", ch1 >> 1); // 0b 0100 0000

	return 0;
}