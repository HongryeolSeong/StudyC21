#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//strncpy
int main()
{
	char str[20] = "mango tree";

	strncpy(str, "apple-pie", 5);
	//str[5] = '\0'; // apple�� ����ϰ����� ��

	printf("%s\n", str);

	return 0;
}