#include <stdio.h>

int main()
{
	char str[80] = "apple juice";
	char* ps = "banana";

	puts(str); // 개행
	fputs(ps, stdout); // 개행x
	puts("milk");

	return 0;
}