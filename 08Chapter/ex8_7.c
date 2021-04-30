#include <stdio.h>

// 배열끝에 널문자가 없는 경우
int main(void)
{
	char str[5];

	str[0] = '0';
	str[1] = 'k';
	//str[2] = '\0';
	printf("%s\n", str);

	return 0;
}