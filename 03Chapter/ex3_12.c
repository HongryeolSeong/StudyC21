#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char name[20];
	int age;
	char address[200];

	printf("이름 : ");
	scanf("%s", name);

	printf("나이 : ");
	scanf("%d", &age);

	printf("주소 : ");
	scanf("%s", address);

	printf("%s은(는) %d살이고 주소는 %s입니다.", name, age, address);

	return 0;
}