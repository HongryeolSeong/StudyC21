#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	// 10���� �ƽ�Ű ����
	int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	int i, res;

	// �ƽ�Ű ���ڵ��� ���̳ʸ�������� a.txt�� ���
	fp = fopen("a.txt", "wb");
	for (i = 0; i < 10; i++)
	{
		fputc(ary[i], fp);
	}
	fclose(fp);

	// a.txt�� �ؽ�Ʈ ���Ϸ� �о����
	fp = fopen("a.txt", "rt");
	while (1)
	{
		res = fgetc(fp);
		if (res == EOF) break; // �ƽ�Ű �ڵ� 26 = -1 = EOF = ^Z
		printf("%4d", res);
	}
	fclose(fp);

	return 0;
}