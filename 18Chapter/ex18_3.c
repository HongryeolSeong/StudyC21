#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	char str[] = "banana";
	int i;

	// ���� ���� - ���� ���
	fp = fopen("b.txt", "w"); // b.txt�� ���� ��� ���� ����
	if (fp == NULL)
	{
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}

	// ���Ͽ� str ���
	i = 0;
	while (str[i] != '\0') // �ι��ڸ� ������ ����
	{
		fputc(str[i], fp); // b.txt�� str�� ���
		i++;
	}
	fputc('\n', fp); // �������� ���� ����
	fclose(fp);

	return 0;
}