#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch1, ch2;
	
	while (1)
	{
		printf("������ �ϳ� �Է��ϼ��� : ");
		scanf(" %c", &ch1);

		if (ch1 >= 'a' && ch1 <= 'z')
		{
			ch2 = ch1 - 32;
			printf("�빮�� ��ȯ ����� : %c", ch2);
		}
		else if (ch1 >= 'A' && ch1 <= 'Z')
		{
			ch2 = ch1 + 32;
			printf("�ҹ��� ��ȯ ����� : %c", ch2);
		}
		else
		{
			printf("���� : �����ڸ� �Է��ϼ���.\n");
		}
		printf("\n");
		printf("\n");
	}

	

	return 0;
}