## Chapter_15 응용 포인터🎯

* 이중포인터   
포인터의 주소를 담는 포인터   
```C
int a = 10;
int *pi;
int **ppi;

pi = &a;
ppi = &pi;
```
pi = &a    * pi = a   
ppi = &pi    * ppi = &a    ** ppi = a   
<br>
   
* 문자열을 가리키는 포인터의 경우
```C
int main()
{
	char* pa = "success";
	char* pb = "failure";
	swap_ptr(&pa, &pb);
}

void swap_ptr(char** ppa, char** ppb) { swap 실행문; }
```
위처럼 함수의 매개변수로 사용시 이중 포인터로 넘긴다. -> pa도 포인터이므로 ** 꼴이 됨.   
포인터 배열의 경우도 마찬가지로 이중 포인터 활용할 것   
<br>
   
* 배열 '요소'의 주소와 '배열'의 주소   
int ary[5]의 경우   
ary + 1 => 1234 + (1 * sizeof(ary[0])) => 1234 + (1 * 4) => 1238   
&ary + 1 => 1234 + (1 * sizeof(ary)) => 1234 + (1 * 20) => 1254   
<br>
   
* 2차원 배열의 경우   
2차원 배열 = 여러 배열들을 가진 1차원 배열 = 여러 포인터들을 가진 1차원 배열   
```C
int main()
{
	int ary[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	print_ary(ary);
}

void print_ary(int (*pa)[4]) { 출력 실행문; } // int* pa[4];는 포인터 배열 선언
```
위처럼 배열 포인터를 선언하여 매개변수로 활용.   
int와 [4]가 자료형이고 * pa를 통해 pa라는 포인터를 선언한다.   
<br>
   
* 함수 포인터   
```C
// 15_7.c
int main()
{
	int (*fp)(int, int); // 함수 포인터 선언
	int res;

	fp = sum; // 함수명을 함수 포인터에 저장
	res = fp(10, 20); // 함수 포인터로 함수 호출
}

int sum(int a, int b) { 더하기 실행문; }
```   
<br>
   
* 함수 포인터를 활용하여 여러 함수를 담고자 할 경우   
```C
// 15_8.c
int main()
{
	int sel;
	scanf("%d", &sel);

	switch (sel)
	{
	case 1: func(sum); break;
	case 2: func(mul); break;
	case 3: func(max); break; // 입력에는 함수 이름을 입력
	}
}

void func(int (*fp)(int, int)) // 포인터로 매개변수 받음과 동시에 함수명을 함수 포인터에 저장
{
	int a, b;
	int res;

	printf("두 정수의 값을 입력하세요 : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b); // 함수 포인터로 함수 호출
	printf("결괏값은 : %d\n", res);
}
```
위처럼 함수 포인터를 매개변수로 받아 여러 함수를 함수 포인터에 넣을 수 있다.     
<br>

* void 포인터   
여러 타입의 변수를 적절하게 포인터에 넣을 수 있음.   
void* vp; 선언 후 * (int * )vp나 * (double * )vp과 같이 형변환 과정을 거쳐야 함.   
   
---
_15장 퀴즈   
14장 퀴즈에서 배열 포인터활용을 추가한   
5명의 학생과 4개 과목의 총합 및 평균 구하기_   
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_stu(int (*pa)[4]);
void print_sub(int (*pa)[4]);

int main()
{
	int score[5][4]; // 2차원 배열
	int i, j;
	char stu = 'A';

	for (i = 0; i < 5; i++)
	{
		printf("%c의 4과목 점수 입력 : ", stu++);
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}
	printf("\n");
	print_stu(score); // 2차원 배열을 배열 포인터로 넘김
	printf("\n");
	print_sub(score); // 2차원 배열을 배열 포인터로 넘김

	return 0;
}

void print_stu(int (*pa)[4]) // 2차원 배열을 배열 포인터로 매개변수 받음
{
	int i, j;
	int total;
	double avg;
	char stu = 'A';

	for (i = 0; i < 5; i++)
	{
		total = 0;
		for (j = 0; j < 4; j++)
		{
			total += pa[i][j];
		}
		avg = total / 4.0;
		printf("%c의 총 점수 : %d, 평균 : %.1lf\n", stu, total, avg);
		stu++;
	}
}

void print_sub(int (*pa)[4]) // 2차원 배열을 배열 포인터로 매개변수 받음
{
	int i, j;
	int total;
	double avg;

	for (j = 0; j < 4; j++)
	{
		total = 0;

		for (i = 0; i < 5; i++)
		{
			total += pa[i][j];
		}

		avg = total / 5.0;

		printf("%d과목 총 점수 : %d, 평균 : %.1lf\n", j + 1, total, avg);
	}
}
```
위처럼 14장 총합평균 퀴즈에서 2차원 배열 사용시 써야할 배열 포인터를 활용하였고, 결과는 같게 나옴을 확인하였다.   
