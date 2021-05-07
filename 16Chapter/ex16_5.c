#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char** ps);

int main()
{
	char temp[80];
	char* str[21] = { 0 }; // 이렇게 선언하면 널포인터로 초기화되는거임
	int i = 0;

	while (i < 20)
	{
		printf("문자열을 입력하세요 : ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		str[i] = (char*)malloc(strlen(temp) + 1); // 각 배열 맨뒤에 널문자를 넣기위해 + 1
		strcpy(str[i], temp);
		i++;
	}
	print_str(str);

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}

	return 0;
}

void print_str(char** ps) // 포인터 배열을 입력받아야 하므로 이중포인터 선언
{
	while (*ps != NULL) // 문자열의 주솟값
	{
		printf("%s\n", *ps);
		ps++;
	}
}