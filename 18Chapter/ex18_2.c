#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	int ch;

	fp = fopen("a.txt", "r"); // �б� ���� ���
	if (fp == NULL)
	{
		printf("������ ������ �ʾҽ��ϴ�.");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp); // ���Ͽ��� ���� �ϳ��� �о����
		if (ch == EOF) // �� �̻� ���� ���ڰ� ���� ���
		{
			break;
		}
		putchar(ch); // ���ۿ� ����� ���ڸ� ȭ�鿡 ���
	}
	fclose(fp);

	return 0;
}