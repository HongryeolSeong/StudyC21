#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
	int id;
	char* name;
	int salary;
}Employee; // struct employee를 Employee로 재정의

int main()
{
	char temp[80];
	int i, total;
	double avg;
	Employee list[5];

	for (i = 0; i < 5; i++)
	{
		printf("%d번째 인원의 아이디, 이름, 급여를 입력하시오. : ", i + 1);
		scanf("%d%s%d", &list[i].id, temp, &list[i].salary);
		list[i].name = (char*)malloc(strlen(temp) + 1);
		if (list[i].name == NULL)
		{
			printf("메모리가 부족합니다.");
			exit(1);
		}
		strcpy(list[i].name, temp); //if (list[i].name != NULL) 사용 해도 됨
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("아이디 : %d, 이름 : %s, 급여 : %d\n", list[i].id, list[i].name, list[i].salary);
	}

	printf("\n");

	total = 0;
	for (i = 0; i < 5; i++)
	{
		total += list[i].salary;
	}
	avg = total / 5.0;
	printf("급여 총액 : %d, 평균 급여 : %.1lf", total, avg);

	printf("\n");

	for (i = 0; i < 5; i++) // 메모리 반환
	{
		free(list[i].name);
	}

	return 0;
}