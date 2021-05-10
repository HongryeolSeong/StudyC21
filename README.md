# StudyC21

PKNU C언어 학습 리포지토리

## Chapter_1 프로그램 만들기

기본적인 visual studio 구동 및 프로젝트 생성

## Chapter_2 상수와 데이터 출력

출력함수 : printf<br>
제어문자 : \n 개행, \b 백스페이스, \r 맨앞으로 이동, \a 벨소리<br>
변환문자 : %d 정수, %lf 실수, %c 문자, %s 문자열, %u 부호없는 10진수<br>

## Chapter_3 변수와 데이터 입력

정수 자료형 : char 1바이트, short 2바이트, int 4바이트, long 4바이트, long long 8바이트<br>
실수 자료형 : float 4바이트, double 8바이트<br>
<br>
문자열 저장 : char 배열명[문자열길이 + 1] = 문자열;<br>
-> 한 번 선언된 후 대입연산으로 문자열 대입 불가<br>
<br>
상수 지정 : const 자료형 변수명 = 값;<br>
<br>
입력함수 : scanf<br>
-> #define _CRT_SECURE_NO_WARNINGS 맨 위에 필수로 사용할 것<br>
-> 배열 입력시 &붙이지 말 것<br>
<br>
---
_3장 퀴즈<br>
정수 다음 바로 문자 입력해야할 경우_<br>
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a;
	char b;

	//정수 다음 문자를 입력받는경우
	printf("정수 하나를 입력하세요 : ");
	scanf("%d", &a);
	printf("문자 하나를 입력하세요 : ");
	scanf(" %c", &b); // or getchar(); 쓸 것.

	printf("입력된 값은 %d, %c 입니다.\n", a, b);
	
	return 0;
}
```

## Chapter_4 연산자

산술 연산자 : +, -, *, /, %<br>
대입 연산자 : =<br>
증감 연산자 : ++a(전위), a--(후위)<br>
관계 연산자 : >, >=, <, <=, ==, !=<br>
논리 연산자 : &&, ||, !<br>
형변환 연산자 : (자료형)피연산자<br>
크기 연산자 : sizeof<br>
복합대입 연산자 : +=, -=, *=, /=, %=<br>
조건 연산자 : res = (a > b) ? a : b; <span style="color:green">// 삼항 연산자라고도 함</span><br>

## Chapter_5 선택문

if (조건식) { 실행문; }<br>
else if (조건식) { 실행문; }<br>
else { 실행문; }<br>
<br>
switch (변수)<br>
case 변수의 값:<br>
   실행문;<br>
   break;<br>
default:<br>
   실행문;<br>
   break;<br>
<br>
---
_5장 퀴즈<br>
if와 switch를 활용한 계산기_<br>
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Calculator_if
int main()
{
	int a, b, res;
	char cal;

	printf("첫번째 값 입력하세요 : ");
	scanf("%d", &a);

	printf("두번째 값 입력하세요 : ");
	scanf("%d", &b);
	getchar();

	printf("원하는 연산을 입력하세요 : ");
	scanf("%c", &cal);

	if (cal == '+')
	{
		res = a + b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '-')
	{
		res = a - b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '*')
	{
		res = a * b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '/')
	{
		res = a / b;
		printf("계산 결과는 : %d입니다.", res);
	}

	return 0;
}
```
---
_Calculator_switch는 나누기 연산의 경우 제수(divisor)가 0이 되지 않도록 구현하였다._
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Calculator_switch
int main()
{
    int a, b, res;
    char cal;

    printf("첫번째 수를 입력하세요 : ");
    scanf("%d", &a);

    printf("두번째 수를 입력하세요 : ");
    scanf("%d", &b);
    getchar();

    printf("원하는 연산을 입력하세요 : ");
    scanf("%c", &cal);

    switch (cal)
    {
    case '+':
        res = a + b;
        printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
        break;
    case '-':
        res = a - b;
        printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
        break;
    case '*':
        res = a * b;
        printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
        break;
    case '/':
        if (b == 0)
        {
            printf("0으로 나눌 수 없습니다.\n");
            main();
        }
        else
        {
            res = a / b;
            printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
            break;
        }
    default:
        break;
    }

    return 0;
}
```

## Chapter_6 반복문

while(조건식) { 실행문; }<br>
for ( 초기식; 조건식; 증감식 ) { 실행문; }<br>
do { 실행문; } while (조건식);<br>

---
_6장 퀴즈<br>
구구단_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, i;

	printf("몇 단 구구단을 실행시키겠습니까? : ");
	scanf("%d", &a);

	if (a > 1 && a < 10)
	{
		for (i = 1; i < 10; i++)
		{
			printf("%d * %d = %d\n", a, i, a * i);
		}
	}
	else
	{
		printf("2 ~ 9 사이의 숫자를 입력하세요.\n");
		main();
	}

	return 0;
}
```
![결과1](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EA%B5%AC%EA%B5%AC%EB%8B%A8.png "구구단")
---
_중복for문 활용한 피라미드 모양 출력_
```C
#include <stdio.h>

int main()
{
	int i, j, k;

	for (i = 1; i < 10; i++)
	{
		for (j = 0; j < 10 - i; j++)
		{
			printf(" ");
		}
		for (k = 0; k < 2*i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
```
![결과2](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%94%BC%EB%9D%BC%EB%AF%B8%EB%93%9C.png "피라미드")
---
_종료기능이 있는 무한반복 계산기_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b, res;
    int i = 1;
    char cal, check;

	while (i)
	{
        printf("원하는 연산을 입력하세요(종료는 y) : ");
        scanf(" %c", &cal);

        if (cal == 'y') break;

        printf("첫번째 수를 입력하세요 : ");
        scanf("%d", &a);

        printf("두번째 수를 입력하세요 : ");
        scanf("%d", &b);

        switch (cal)
        {
        case '+':
            res = a + b;
            printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
            break;
        case '-':
            res = a - b;
            printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
            break;
        case '*':
            res = a * b;
            printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
            break;
        case '/':
            if (b == 0)
            {
                printf("0으로 나눌 수 없습니다.\n");
                main();
            }
            else
            {
                res = a / b;
                printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
                break;
            }
        default:
            break;
        }

        printf("\n");

        printf("끝내시겠습니까? ");
        scanf(" %c", &check);

        if (check == 'y')
        {
            break; // while(i)문 탈출
        }
        else
        {
            i = 1;
        }

        printf("\n");
	}

	return 0;
}
```
![결과3](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EA%B3%84%EC%82%B0%EA%B8%B0.png "계산기")


## Chapter_7 함수

