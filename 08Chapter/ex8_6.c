#include <stdio.h>

int main()
{
	char str[80];

	printf("���ڿ� �Է� : ");
	gets(str); // gets : ���� ���Ե� ���ڿ� �Է�
	puts("�Էµ� ���ڿ� : "); // puts : �ڵ� ����
	puts(str);

	return 0;
}