#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char** ps);

int main()
{
	char temp[80];
	char* str[21] = { 0 }; // �̷��� �����ϸ� �������ͷ� �ʱ�ȭ�Ǵ°���
	int i = 0;

	while (i < 20)
	{
		printf("���ڿ��� �Է��ϼ��� : ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		str[i] = (char*)malloc(strlen(temp) + 1); // �� �迭 �ǵڿ� �ι��ڸ� �ֱ����� + 1
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

void print_str(char** ps) // ������ �迭�� �Է¹޾ƾ� �ϹǷ� ���������� ����
{
	while (*ps != NULL) // ���ڿ��� �ּڰ�
	{
		printf("%s\n", *ps);
		ps++;
	}
}