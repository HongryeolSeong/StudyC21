#include <stdio.h>

int main()
{
	int ch;

	while (1)
	{
		// ���� 1. getchar()�� �Լ� ���������� stdin���
		ch = getchar(); // ���� ������ ���x

		// ���� 2. ���� �����ͷ� stdin�� �޾� ����ϴ� fgetc()
		//ch = fgetc(stdin);

		if (ch == EOF)
		{
			break;
		}

		// ����1. putchar()�� �Լ� ���������� stdout���
		putchar(ch); // ���� ������ ���x

		// ���� 2. ���� �����ͷ� stdout�� �޾� ����ϴ� fputc()
		//fputc(ch, stdout);
	}

	return 0;
}