#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp; // ���� ����ü�� ����Ű�� ������

	// ���� ����
	// fopen()�� ������ ã�� �⺻ ��ġ�� "���� �۾� ���͸�"
	fp = fopen("a.txt", "r"); // ���� ������ ��� ��Ʈ�� ������ ������ �ּҸ� ��� fp
	if (fp == NULL) // ������ ���� ��� = �ּҰ� NULL
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return 1; // ���α׷� ����
	}
	printf("������ ���Ƚ��ϴ�.\n");

	// ���� ���
	fclose(fp);

	return 0;
}