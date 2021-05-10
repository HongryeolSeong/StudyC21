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

함수 작성 종류<br>
1. 메인 함수에 작성   
2. 입출력이 없는 함수 작성 : void func() { 실행문; }   
3. 입력이 있는 함수 작성 : void func( 매개변수1 선언, 매개변수2 선언 ) { 실행문; }   
4. 입출력이 있는 함수 작성 : 반환타입 func( 매개변수1 선언, 매개변수2 선언 ) { 실행문; return 반환할 변수; }   

---
_7장 퀴즈   
여러 함수를 활용한 계산기_   
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum();
int minus();
int multi();
int divi();
int value1();
int value2();

int main()
{
	int res;
	char cal;

	while (1)
	{
		printf("원하는 메뉴 선택하세요.");
		scanf(" %c", &cal);

		switch (cal)
		{
		case '+':
			res = sum();
			printf("결과는 : %d", res);
			break;
		case '-':
			res = minus();
			printf("결과는 : %d", res);
			break;
		case '*':
			res = multi();
			printf("결과는 : %d", res);
			break;
		case '/':
			res = divi();
			printf("결과는 : %d", res);
			break;
		case 'q':
			exit(1);
		default:
			break;
		}

		printf("\n");
		printf("\n");
	}

	return 0;
}

int sum()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a + b;

	return res;
}

int minus()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a - b;

	return res;
}

int multi()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a * b;

	return res;
}

int divi()
{
	int a, b;
	int res = 0;

	a = value1();
	b = value2();

	if (b == 0)
	{
		printf("나누는 수는 0이 되면 안됩니다.\n");
	}
	else
	{
		res = a / b;
	}

	return res;
}

int value1()
{
	int a;

	printf("첫 번째 숫자를 입력하세요 : ");
	scanf("%d", &a);
		
	return a;
}

int value2()
{
	int b;
	
	printf("두 번째 숫자를 입력하세요 : ");
	scanf("%d", &b);

	return b;
}
```
![결과4](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%95%A8%EC%88%98%EA%B3%84%EC%82%B0%EA%B8%B0.png "함수계산기")

## Chapter_8 배열

정수형 : int ary[5] = { 초기화할 값 };   
문자형 : char str[80] = { 'a', 'b' }; or "ab";   
* 문자열의 마지막 요소는 무조건 '\0'
* 문자형은 한 번 초기화 후 변경시 strcpy() 사용해야함.   
* gets() : Enter입력 전까지 모든 문자를 문자열에 저장하는 함수   
* puts() : 문자열 출력 함수. 자동 개행 기능을 가짐   

## Chapter_9 포인터

변수의 주소 : ex) int a;의 경우 &a는 a의 시작 주소 값   
그 주소를 담는 포인터
* int* pa; pa = &a;의 경우 pa는 a의 시작 주소 값을 담는 포인터(변수)
* *pa는 pa가 가리키는 주소인 a의 데이터 값
* 포인터가 가리키는 자료형과 변수의 데이터타입은 무조건 동일하게 선언
* 포인터의 크기는 주소를 담으므로 항상 4byte   

   
포인터 및 포인터가 가리키는 데이터의 상수화   
const int* pa = &a; // 포인터가 가리키는 곳의 데이터를 상수화, pa 간접참조로 a값 못 바꾸게하는 기능   
* //*pa = 30; // 불가   
int* const pb = &b; // 포인터 자체가 상수화   
* //pb = &a; // 불가   

---
_9장 예제   
포인터를 써야하는 이유_   
```C
#include <stdio.h>

void swap(int* pa, int* pb);

int main()
{
	int a = 10, b = 20;

	printf("a:%d, b:%d\n", a, b);
	swap(&a, &b);
	printf("a:%d, b:%d\n", a, b);

	return 0;
}

void swap(int* pa, int* pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
```
_위의 코드에서 포인터 사용안할시 a와 b의 값은 바뀌지 않는다._   

## Chapter_10 배열과 포인터

컴파일러는 배열명을 배열의 첫 번째 요소의 주소로 변경한다   
배열명처럼 사용되는 포인터   
* ex) int* pa = ary;이면 pa[2] = pa[1] + pa[0]과 같은 연산이 가능
* pa는 변수라 pa++, pa + i와 같은 연산이 되지만, ary는 상수라 불가   
   
주소 연산시 : 주소 + 정수 => 주소 + (정수 * 해당 주소를 가지는 변수의 크기)   
포인터 연산시 : 포인터 - 포인터 => 값의 차 / 가리키는 자료형의 크기   
   
함수의 입력변수로 배열 사용시, 함수의 매개변수로 포인터를 선언해야함   

_10장 퀴즈   
한 배열의 요소를 거꾸로 출력하는 함수_   
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_ary(int* pa, int size);
void swap_ary(int* pa, int size);
void print_ary(int* pa, int size);

int main()
{
	int ary[10];
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	swap_ary(ary, size);
	print_ary(ary, size);

	return 0;
}

void input_ary(int* pa, int size)
{
	int i;

	printf("%d개의 정수값 입력 : ", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", pa + i);
	}
}

void swap_ary(int* pa, int size)
{
	int temp, i;
	int* px = pa;
	int* py = pa + 9;

	for (i = 0; i < 5; i++)
	{
		temp = *(px + i);
		*(px + i) = *(py - i);
		*(py - i) = temp;
	}

}

void print_ary(int* pa, int size)
{
	int i;

	printf("배열 출력\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
}
```
![결과5](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EA%B1%B0%EA%BE%B8%EB%A1%9C.png "거꾸로출력")

## Chapter_11 문자

'a'로 입력된 문자 a는 컴파일을 통해 아스키 코드 값으로 바뀐다   
그러므로 'a' - 65와 같은 연산 가능   
   
띄어쓰기와 엔터도 문자의 일종이므로(아스키 코드 값 가짐)   
입력받을시 화이트 스페이스를 활용해야한다.   
ex) scanf("%c%c", &ch1, &ch2); -> scanf(" %c %c", &ch1, &ch2);
