#include <stdio.h>

int main()
{
	int ch;

	while (1)
	{
		// 예제 1. getchar()는 함수 내부적으로 stdin사용
		ch = getchar(); // 파일 포인터 사용x

		// 예제 2. 파일 포인터로 stdin을 받아 사용하는 fgetc()
		//ch = fgetc(stdin);

		if (ch == EOF)
		{
			break;
		}

		// 예제1. putchar()는 함수 내부적으로 stdout사용
		putchar(ch); // 파일 포인터 사용x

		// 예제 2. 파일 포인터로 stdout을 받아 사용하는 fputc()
		//fputc(ch, stdout);
	}

	return 0;
}