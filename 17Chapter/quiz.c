#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
	int id;
	char* name;
	int salary;
}Employee; // struct employee�� Employee�� ������

int main()
{
	char temp[80];
	int i, total;
	double avg;
	Employee list[5];

	for (i = 0; i < 5; i++)
	{
		printf("%d��° �ο��� ���̵�, �̸�, �޿��� �Է��Ͻÿ�. : ", i + 1);
		scanf("%d%s%d", &list[i].id, temp, &list[i].salary);
		list[i].name = (char*)malloc(strlen(temp) + 1);
		if (list[i].name == NULL)
		{
			printf("�޸𸮰� �����մϴ�.");
			exit(1);
		}
		strcpy(list[i].name, temp); //if (list[i].name != NULL) ��� �ص� ��
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("���̵� : %d, �̸� : %s, �޿� : %d\n", list[i].id, list[i].name, list[i].salary);
	}

	printf("\n");

	total = 0;
	for (i = 0; i < 5; i++)
	{
		total += list[i].salary;
	}
	avg = total / 5.0;
	printf("�޿� �Ѿ� : %d, ��� �޿� : %.1lf", total, avg);

	printf("\n");

	for (i = 0; i < 5; i++) // �޸� ��ȯ
	{
		free(list[i].name);
	}

	return 0;
}