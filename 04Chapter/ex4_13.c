#include <stdio.h>

int main()
{
	int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a ^ b);
	printf("a | b : %d\n", a | b);
	printf("~a : %d\n", ~a);
	printf("a << 1 : %d\n", a << 1); // �� ������ ���� ������ 0�� ä����
	printf("a >> 2 : %d\n", a >> 2); // �� ���� ���� ��ȣ��Ʈ�� ���� ���� ä����

	char ch = 128; // 0b 1000 0000
	unsigned char ch1 = 128;
	printf("ch >> 1 : %d\n", ch >> 1); // 0b 1100 0000
	printf("ch >> 1 : %d", ch1 >> 1); // 0b 0100 0000

	return 0;
}