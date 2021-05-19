## Chapter_19 전처리와 분할 컴파일🎯

* 파일을 포함하는 전처리 지시자 #include   
<> : 컴파일러가 제공하는 디렉터리에서 검색   
"" : 소스 파일이 저장된 디렉터리에서 검색   
"c:\user\a.h"와 같이 다른 디렉터리에서도 검색 가능   
   
```C
// student.h
typedef struct
{
	int num;
	char name[20];
} Student;
```
```C
// main.c
#include <stdio.h>
#include "student.h" // 사용자 헤더파일

int main()
{
	Student a = { 315, "홍길동" };

	printf("학번 : %d, 이름 : %s\n", a.num, a.name);
}
```   
위처럼 #include를 사용하여 메인 소스에 헤더 파일을 참조할 수 있다.   
<br>

* 매크로명을 만드는 전처리 지시자 #define   
자주 사용하는 복잡한 숫자, 문자열 등을 간단한 단어로 표현   
대문사 사용할 것   
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n");

int main()
{
	double radius, area;

	printf("반지름을 입력하세요(10 이하) : ");
	scanf("%lf", &radius);
	area = PI * radius * radius;
	if (area > LIMIT) ERR_PRN
	else printf("원의 면적 : %.2lf (%s)\n", area, MSG);
}
```
<br>

* #define을 사용한 매크로 함수   
```C
#include <stdio.h>
#define SUM(a, b) ((a) + (b))
#define MUL(a, b) ((a) * (b))
#define test(a) (a * 10)

int main()
{
	int a = 10, b = 20;
	int x = 30, y = 40;
	int res;

	printf("a + b = %d\n", SUM(a, b));
	printf("x + y = %d\n", SUM(x, y));
	res = 30 / MUL(2, 5);
	printf("res : %d\n", res);
	
	printf("%d\n", test(a + 10)); 
	// 원래 200 나와야 하지만 110출력
	// -> #define test(a) ((a) * (10))이 되야함
}
```   
<br>

* 이미 정의된 매크로   
사용자가 취소하거나 바꿀 수 없다.   
```C
#include <stdio.h>

void func(void);

int main()
{
	printf("컴파일 날짜와 시간 : %s, %s\n\n", __DATE__, __TIME__);
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__);

#line 100 "marco.c" // 행번호를 100번부터 시작, 파일명은 marco.c로 표시
	func(); 

	return 0;
}

void func(void)
{
	printf("\n");
	printf("파일명 : %s\n", __FILE__);
	printf("함수명 : %s\n", __FUNCTION__);
	printf("행번호 : %d\n", __LINE__); // 요기부터 100번 행
}
```   
<br>

* 매크로 연산자 #, ##   
'#' : 인수를 문자열로 치환   
'##' : 두 토큰을 붙여 하나로 만듦   
```C
#include <stdio.h>
#define PRINT_EXPR(x) printf(#x " = %d\n", x)
#define NAME_CAT(x, y) (x ## y)

int main()
{
	int a1, a2;

	NAME_CAT(a, 1) = 10; // a1 = 10;
	NAME_CAT(a, 2) = 20; // a2 = 20;
	PRINT_EXPR(a1 + a2); // printf("a1 + a2" " = %d\n", a1 + a2);
	PRINT_EXPR(a2 - a1); // printf("a2 - a1" " = %d\n", a2 - a1);

	return 0;
}
```
<br>

* 조건부 컴파일 지시자   
소스코드를 조건에 따라 선택적으로 컴파일하게 하는 역할   
```C
#include <stdio.h>
#define VER 7
#define BIT16

int main()
{
	int max;

#if VER >=6;
	printf("버전 %d입니다.\n", VER);
#endif

#ifdef BIT16 // 매크로명 BIT16이 정의 돼있다면
// != #ifndef
	max = 32767;
#else // 안돼있다면
	max = 2147483647;
#endif

	printf("int형 변수의 최댓값 : %d\n", max);

	return 0;
}
```
<br>

* #pragma 지시자   
컴파일 방법을 세부적으로 제어할 때   
```C
#include <stdio.h>
#pragma pack(push, 1) // #pragma pack(1)도 가능
// 바이트 얼라인먼트를 1로 바꿈
// -> 단위 크기를 1로 설정 -> 구조체 멤버가 모든 위치에 할당
// -> 이후 정의된 구조체는 모두 패딩바이트 포함x
// -> 구초제의 크기는 멤버들의 크기를 더한 것과 같다
typedef struct
{
	char ch;
	int in;
} Sample1;

// 바꾸기 전의 바이트 얼라인먼트 규칙을 적용 시
#pragma pack(pop)
typedef struct
{
	char ch;
	int in;
} Sample2;

int main()
{
	printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
	printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));

	return 0;
}
```
<br>

* 분할 컴파일   
한 프로그램을 여러 모듈로 나누어 컴파일시   
-> 쉬운 디버깅/유지보수   
-> 코드 재활용 용이   
-> 여러 명이 코드 작업 가능   
<br>

* extern, static   
분할 작업시 전역 변수의 공유에 대한 방법   
extern : 다른 파일에 선언된 전역 변수를 공유하기 위한 예약어   
static : 전역 변수가 다른 파일에서 공유되지 못하게 하는 예약어   
```C
// main.c
#include <stdio.h>

int input_data(void);
double average(void);
void print_data(double);

int count = 0;
static int total = 0; // input.c의 전역 변수 total과 중복 차단위해

int main()
{
	double avg;

	total = input_data();
	avg = average();
	print_data(avg);

	return 0;
}

void print_data(double avg)
{
	printf(" 입력한 양수의 개수 : %d\n", count);
	printf(" 전체 합과 평균 : %d, %.1lf\n", total, avg);
}
```
```C
// input.c
#include <stdio.h>

extern int count; // main.c의 전역 변수인 count를 공유
int total = 0;

int input_data(void)
{
	int pos;

	while (1)
	{
		printf("양수 입력 : ");
		scanf("%d", &pos);
		if (pos < 0) break;
		count++;
		total += pos;
	}

	return total;
}
```
```C
// average.c
extern int count; // main.c의 count
extern int total; // input.c의 total

double average(void)
{
	return total / (double)count;
}
```
<br>

* 헤더 파일의 필요성
한 함수를 여러 파일에서 사용하는 경우 -> 각 파일에 모두 여러 번 함수 선언이 필요   
한 전역 변수를 여러 파일에서 공유하는 경우 -> 각 파일에 모두 extern 선언이 필요   
--> 헤더 파일을 만들어 인클루드 함으로써 여러 번의 선언을 최소화 함.   
<br>

* 중복 문제 해결   
두 번 이상 인클루드 실행 시 중복 문제 발생   
조건부 컴파일 지시자 ifndef를 사용하여 해결   
```C
// main.c
#include <stdio.h>
#include "point.h"
#include "line.h"

int main()
{
	Line a = { {1, 2}, {5, 6} };
	// line.h를 인클루드하며
	// 이미 인클루드 된 point.h를
	// 한 번 더 인클루드 하게 됨 -> 중복 발생
	Point b;

	b.x = (a.first.x + a.second.x) / 2;
	b.y = (a.first.y + a.second.y) / 2;
	printf("선의 가운데 점의 좌표 : (%d, %d)\n", b.x, b.y);

	return 0;
}
```
```C
// point.h
#ifndef _POINT_H_
#define _POINT_H_

typedef struct
{
	int x;
	int y;
} Point;

#endif
```
```C
// line.h
#include "point.h"
#ifndef _LINE_H_
#define _LINE_H_

typedef struct
{
	Point first;
	Point second;
} Line;

#endif
```
위처럼 컴파일시 main에서 이미 point.h를 인클루드 했지만   
line.h에서 한 번 더 point.h를 인클루드 하여 중복 인클루드가 발생하므로   
조건부 컴파일 지시자를 사용하여 중복 문제를 해결하였다.   
<br>
