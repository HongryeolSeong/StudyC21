#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct      // 구조체 선언
{
	int num;		// 회원의 회원 번호
	char name[20];	// 회원의 이름
	double weight;	// 회원의 몸무게
} Fitness;

void total_number(int count);						// 전체 등록 회원 수 출력
double average_weight(Fitness** pary, int count);	// 평균 체중 반환
int max_weight(Fitness** pary, int count);			// 최대 체중 회원의 index 반환
void print_info(Fitness** pary, int index);			// 회원 정보 출력
void free_ary(Fitness** pary, int count);			// 동적 할당 영역 해제

Fitness* ary[100];			// 포인터 배열 선언

int main()
{
	int i;						// 반복문 i
	int count = 0;				// 총 회원 수
	int tnum;					// 회원 번호 임시 변수
	char tname[80];				// 회원 이름 임시 배열
	double tw;					// 회원 체중 임시 변수
	double avg;					// 전체 회원의 평균 체중
	int index;					// 회원 정보가 담긴 배열의 인덱스


	while (1)
	{
		// 1. 회원 번호 입력
		printf("> 회원 번호 : ");
		scanf("%d", &tnum);
		if (count == 0) // 맨 처음 음수 입력시
		{
			if (tnum < 0) return 0; // 프로그램 종료
		}
		else if (count > 0) // 두번째 이상부터 음수 입력시
		{
			if (tnum < 0) break; // 반복문 탈출
		}
		getchar();


		// 2. 회원 이름 입력
		printf("> 이름 입력 : ");
		gets(tname);

		// 3. 회원 체중 입력
		printf("> 체중 입력 : ");
		scanf("%lf", &tw);
		while ((tw < 0) || (tw > 560)) // 정확한 몸무게 입력 유도
		{
			printf("몸무게는 1~560사이 숫자를 입력하세요.\n");
			printf("> 체중 입력 : ");
			scanf("%lf", &tw);
		}

		// 4. 동적 할당을 통한 멤버 변수들의 heap영역 저장
		ary[count] = (Fitness*)malloc(sizeof(Fitness));
		ary[count]->num = tnum;
		strcpy(ary[count]->name, tname);
		ary[count]->weight = tw;

		count++;
	}

	total_number(count);				// 총 회원수 출력
	avg = average_weight(ary, count);	// 평균 체중 출력
	index = max_weight(ary, count);		// 최고 체중의 인덱스
	print_info(ary, index);				// 최고 체중을 가진 회원 출력
	free_ary(ary, count);				// 동적 할당 해제

	return 0;
}

// 전체 등록 회원 수 출력
void total_number(int count)
{
	printf("# 총 회원 수 : %d\n", count);
}

// 평균 체중 반환
double average_weight(Fitness** pary, int count)
{
	int i;
	int res;
	double avg;

	res = 0;

	for (i = 0; i < count; i++)
	{
		res += pary[i]->weight;	// 회원들 몸무게 총합
	}

	avg = res / (double)count;	// res를 통해 회원들 몸무게 평균을 구함

	printf("# 평균 체중 : %.1lf\n", avg);

	return avg;
}

// 최대 체중 회원의 index 반환
int max_weight(Fitness** pary, int count)
{
	int i;
	int maxindex = 0;			// 반환 시킬 최대 체중 회원의 index

	for (i = 1; i < count; i++)	// 2번째 요소부터 비교 시작
	{
		if (pary[maxindex]->weight < pary[i]->weight)	// 매 횟수마다 최대 체중 회원의
		{												// 몸무게보다 큰 회원이 있을 경우
			maxindex = i;								// 그 회원의 인덱스를
		}												// maxindex에 저장
	}

	return maxindex;
}

// 회원 정보 출력
void print_info(Fitness** pary, int index)
{
	// 최대 체중 회원의 정보 출력
	printf("# 체중이 가장 무거운 회원은?\n");
	printf("> 회원 번호 : %d\n", pary[index]->num);
	printf("> 이름 : %s\n", pary[index]->name);
	printf("> 체중 : %.1lf\n", pary[index]->weight);
}

// 동적 할당 영역 해제
void free_ary(Fitness** pary, int count)
{
	int i;

	for (i = 0; pary[i] != NULL; i++)	// 매개변수로 넘어온 ary의 요소가 NULL바로 전까지
	{
		free(pary[i]);					// 요소별로 동적 할당 해제
	}
}