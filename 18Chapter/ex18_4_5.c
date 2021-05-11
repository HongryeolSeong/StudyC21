#include <stdio.h>

int main()
{
	int ch;

	while (1)
	{
		//ch = getchar();
		ch = fgetc(stdin);

		if (ch == EOF)
		{
			break;
		}

		//putchar(ch);
		fputc(ch, stdout);
	}

	return 0;
}