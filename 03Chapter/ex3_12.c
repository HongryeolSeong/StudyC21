#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char name[20];
	int age;
	char address[200];

	printf("�̸� : ");
	scanf("%s", name);

	printf("���� : ");
	scanf("%d", &age);

	printf("�ּ� : ");
	scanf("%s", address);

	printf("%s��(��) %d���̰� �ּҴ� %s�Դϴ�.", name, age, address);

	return 0;
}