#include <stdio.h>

int main()
{
	char str[80];

	printf("������ ���Ե� ���ڿ� �Է� : ");
	gets(str); // ���� ���Ե� ���ڿ� �Է� ����
	printf("�Է��� ���ڿ��� %s�Դϴ�.", str);

	return 0;
}