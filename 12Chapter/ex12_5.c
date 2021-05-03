#include <stdio.h>

int main()
{
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	fgets(str, sizeof(str), stdin); // 키보드로 입력할땐 stdin(스트림)

	printf("입력된 문자열은 %s입니다.\n", str);

	return 0;
}