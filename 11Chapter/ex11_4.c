#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch;
	int i;

	for (i = 0; i < 6; i++)
	{
		// �Էµ� ���ڰ� ���ۿ� ������ ����
		scanf("%c", &ch); // ������ ���ڸ� �ϳ��� ������
		printf("%c", ch);
	}

	return 0;
}