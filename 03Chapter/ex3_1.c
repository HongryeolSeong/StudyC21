#include <stdio.h>

int main()
{
	int a;
	int b, c;
	double da;
	char ch;

	a = 10;
	b = a;
	c = a + 20;
	da = 3.5;
	ch = 'A';

	printf("���� a�� �� : %d\n", a);
	printf("���� b�� �� : %d\n", b);
	printf("���� c�� �� : %d\n", c);
	printf("���� da�� �� : %.1lf\n", da);
	printf("���� ch�� �� : %c\n", ch);

	printf("char ũ�� : %d\n", sizeof(char));
	printf("int ũ�� : %d\n", sizeof(int));
	printf("double ũ�� : %d\n", sizeof(double));
	printf("long ũ�� : %d\n", sizeof(long));
	printf("short ũ�� : %d\n", sizeof(short));

	return 0;
}