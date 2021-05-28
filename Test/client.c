#include <stdio.h>

typedef struct      // 구조체 선언
{
	int num;
	char name[20];
	int weight;
} Fitness;

Fitness* ary[100];									// 포인터 배열 선언
void total_number(int count);						// 전체 등록 회원 수 반환
int average_weight(Fitness** pary, int count);	// 평균 체중 반환
int max_weight(Fitness** pary, int count);			// 최대 체중 회원의 index 반환
void print_info(Fitness** pary, int index);			// 회원 정보 출력
void free_ary(Fitness** pary, int count);			// 동적 할당 영역 해제

int main()
{
	int i = 0;
	int count;
	int avg;
	Fitness list[100];

	while (1)
	{
		printf("> 회원 번호 : ");
		scanf("%d", &list[i].num);
		if (list[i].num < 0) break;
		getchar();

		printf("> 이름 입력 : ");
		gets(list[i].name);

		printf("> 체중 입력 : ");
		scanf("%d", &list[i].weight);
		getchar();


		i++;
	}
	count = i;

	total_number(count);
	avg = average_weight(list, count);

	return 0;
}

void total_number(int count)
{
	printf("# 총 회원 수 : %d", count);
}

int average_weight(Fitness** pary, int count)
{
	int i;
	int res;
	int avg;

	res = 0;

	for (i = 0; i < count; i++)
	{
		res += pary[i]->weight;
	}

	avg = res / count;

	printf("# 평균 체중 : %.1lf", avg);

	return avg;
}

int max_weight(Fitness** pary, int count)
{
	int i, j;
	printf("체중이 가장 무거운 회원은?\n");
	for (i = 0; i < count; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (pary[j]->weight > pary[i]->weight) break;
		}
	}
}

void print_info(Fitness** pary, int index)
{

}

void free_ary(Fitness** pary, int count)
{

}