# StudyC21

PKNU C언어 학습 리포지토리
<br>
<br>
<br>
## Chapter_1 프로그램 만들기🎯

기본적인 visual studio 구동 및 프로젝트 생성
<br>
<br>
<br>
## Chapter_2 상수와 데이터 출력🎯

출력함수 : printf<br>
제어문자 : \n 개행, \b 백스페이스, \r 맨앞으로 이동, \a 벨소리<br>
변환문자 : %d 정수, %lf 실수, %c 문자, %s 문자열, %u 부호없는 10진수<br>
<br>
<br>
## Chapter_3 변수와 데이터 입력🎯

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
<br>
<br>

## Chapter_4 연산자🎯

산술 연산자 : +, -, *, /, %<br>
대입 연산자 : =<br>
증감 연산자 : ++a(전위), a--(후위)<br>
관계 연산자 : >, >=, <, <=, ==, !=<br>
논리 연산자 : &&, ||, !<br>
형변환 연산자 : (자료형)피연산자<br>
크기 연산자 : sizeof<br>
복합대입 연산자 : +=, -=, *=, /=, %=<br>
조건 연산자 : res = (a > b) ? a : b; <span style="color:green">// 삼항 연산자라고도 함</span><br>
<br>
<br>
## Chapter_5 선택문🎯

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
<br>
<br>
<br>

## Chapter_6 반복문🎯

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
<br>
<br>
<br>

## Chapter_7 함수🎯

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
<br>
<br>
<br>

## Chapter_8 배열🎯

정수형 : int ary[5] = { 초기화할 값 };   
문자형 : char str[80] = { 'a', 'b' }; or "ab";   
* 문자열의 마지막 요소는 무조건 '\0'
* 문자형은 한 번 초기화 후 변경시 strcpy() 사용해야함.   
* gets() : Enter입력 전까지 모든 문자를 문자열에 저장하는 함수   
* puts() : 문자열 출력 함수. 자동 개행 기능을 가짐   
<br>
<br>

## Chapter_9 포인터🎯

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
<br>
<br>

## Chapter_10 배열과 포인터🎯

컴파일러는 배열명을 배열의 첫 번째 요소의 주소로 변경한다   
배열명처럼 사용되는 포인터   
* ex) int* pa = ary;이면 pa[2] = pa[1] + pa[0]과 같은 연산이 가능
* pa는 변수라 pa++, pa + i와 같은 연산이 되지만, ary는 상수라 불가   
   
주소 연산시 : 주소 + 정수 => 주소 + (정수 * 해당 주소를 가지는 변수의 크기)   
포인터 연산시 : 포인터 - 포인터 => 값의 차 / 가리키는 자료형의 크기   
   
함수의 입력변수로 배열 사용시, 함수의 매개변수로 포인터를 선언해야함   

---
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
---
   
_10장 퀴즈2   
중복된 번호는 입력불가한 로또 배열_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_lotto(int* pl, int size);
void print_lotto(int* pl, int size);

int main()
{
	int lotto[6];
	int size = sizeof(lotto) / sizeof(lotto[0]);

	input_lotto(lotto, size);
	printf("\n");
	print_lotto(lotto, size);

	return 0;
}

void input_lotto(int* pl, int size)
{
	int flag = 0;
	int i = 0;
	int j;
	int temp;


	while (i < size)
	{
		printf("로또 번호 입력 : ");
		scanf("%d", &temp);
		if (i == 0)
		{
			flag = 1;
		}
		else if (i > 0)
		{
			for (j = 0; j < i; j++)
			{
				if (temp == pl[j])
				{
					printf("중복된 숫자를 입력하지 마시오.\n");
					flag = -1; // 중복된 숫자가 있다는 플래그
					break; // for문을 탈출하여 해당 순서의 번호 입력으로 다시 돌아감
				}
				flag = 1; // 중복된 숫자가 없다는 플래그
			}
		}

		if (flag > 0) // 중복된 숫자 없는경우 로또 배열에 번호 입력
		{
			*(pl + i) = temp;
			i++;
		}
	}
}

void print_lotto(int* pl, int size)
{
	int i;

	printf("로또 번호 출력\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", *(pl + i));
	}
}
```
![결과6](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EB%A1%9C%EB%98%90.png "")
<br>
<br>
<br>

## Chapter_11 문자🎯

'a'로 입력된 문자 a는 컴파일을 통해 아스키 코드 값으로 바뀐다   
그러므로 'a' - 65와 같은 연산 가능   
   
띄어쓰기와 엔터도 문자의 일종이므로(아스키 코드 값 가짐)   
입력받을시 화이트 스페이스를 활용해야한다.   
ex) scanf("%c%c", &ch1, &ch2); -> scanf(" %c %c", &ch1, &ch2);   
   
scanf의 경우 모든 자료형을 입력받을 수 있으므로 무거움   
-> 문자만 입출력하는 경우 전용 함수(ch = getchar();, putchar(ch);) 사용시 효율적.   
--> getchar의 경우 getchar();만 사용시 개행문자를 제거하는 기능이 있다   

---
_11장 퀴즈   
대소문자 변환_   
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch1, ch2;
	
	while (1)
	{
		printf("영문자 하나 입력하세요 : ");
		scanf(" %c", &ch1);

		if (ch1 >= 'a' && ch1 <= 'z')
		{
			ch2 = ch1 - 32;
			printf("대문자 변환 결과는 : %c", ch2);
		}
		else if (ch1 >= 'A' && ch1 <= 'Z')
		{
			ch2 = ch1 + 32;
			printf("소문자 변환 결과는 : %c", ch2);
		}
		else
		{
			printf("오류 : 영문자를 입력하세요.\n");
		}
		printf("\n");
	}

	

	return 0;
}
```
![결과7](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EB%8C%80%EC%86%8C%EB%AC%B8%EC%9E%90.png "대소문자")
---
<br>
<br>
<br>

## Chapter_12 문자열🎯

배열과 마찬가지로 문자열은 그 문자열의 첫 문자가 시작하는 주소와 같다.   
   
fgets
* fgets(str, sizeof(str), stdin);
* 입력받는 문자열의 크기를 확인하여 할당된 메모리를 넘어서지 않는지 체크 후 입력.
   
fgetc
* fgetc(stdin);
* 어떤 입력 다음 문자 입력시 개행문자의 방해를 없애기 위해.
* getchar()와 scanf("%c")와 동일
   
fputs
* fputs(str, stdout);
* puts와 달리 자동 개행 함수
   
strcpy, strncpy
* strcpy(str2, str1);, strncpy(str, 복사할 문자열, 원하는 문자 갯수);
   
strcat, strncat
* strcat(str, 붙일 문자열);, strncat(str, 붙일 문자열, 원하는 문자 갯수);
   
strlen
* strlen(str); 문자열의 길이 측정.
   
strcmp, strncmp
* strcmp(str1, str2);, strncmp(str1, str2, 비교할 문자 갯수);
   
---
_12장 퀴즈   
직접 만드는 gets 함수_   
```C
#include <stdio.h>

void my_gets(char* ps);

int main()
{
	int i = 0;
	char str[20];
	char ch;

	/*do
	{
		ch = getchar();
		str[i] = ch;
		i++;
	} while (ch != '\n');

	str[i] = '\0';*/

	my_gets(str);

	printf("%s", str);

	return 0;
}

void my_gets(char* ps)
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		*ps = ch;
		ps++;
	}
	*ps = '\0';
}
```
<br>
<br>

## Chapter_13 변수의 영역과 데이터 공유🎯

변수 종류에 따른 영역
1. 지역 변수 : 함수/블럭 내에서만 생존. 함수나 블럭 종료시 메모리 반환되어 사용 불가 //스택 영역
2. 전역 변수 : 한 프로그램 내에서 생존. 초기화 없을시 자동으로 0으로 초기화 // 데이터 영역
3. static 지역 변수 // 데이터 영역
* 함수/블록이 끝나도 지역변수의 저장 공간 유지
* 프로그램 종료시까지 존재
* 하지만 블럭안에서만 수정 가능
* 따로 초기화 안할시 0으로 자동 초기화
4. 레지스터 변수 : 레지스터의 속도를 활용한 변수 // 레지스터 영역
<br>

데이터 공유 방법
1. 값 복사해서 전달 -> 함수의 입력
2. 주소를 전달 -> 함수의 입력
3. 값을 함수 입력으로 받아 주소를 반환
<br>
<br>

## Chapter_14 다차원 배열과 포인터🎯

1차원 배열 : int str[5];   
2차원 배열 : int str[4][5];   
초기화 시
```C
int num[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
```
3차원 배열
```C
int score[2][3][4] = {
		{ { 72, 80, 95, 60 }, { 68, 98, 83, 90 }, { 75, 72, 84, 90 } }, // 면1
		{ { 66, 85, 90, 80 }, { 95, 92, 88, 95 }, { 43, 72, 56, 75 } } // 면2
	};
```
<br>

2차원 char 배열 : char animal[5][20];   
-> 1차원 char 배열 = 하나의 문자열 이므로, 여러 문자열을 저장하려면 여러 1차원 char 배열이 필요하다.   
-> 한 행에 한 문자열이 저장되는 꼴   
초기화 시
```C
char animal[][10] = { "dog", "tiger", "rabbit", "horse", "cat" };
```
<br>

---
_예제) 5명 학생의 총합과 평균 그리고 4개 과목의 총합과 평균_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[5][4];
	int total1, total2;
	double avg1, avg2;
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
	stu = 'A';


	for (i = 0; i < 5; i++)
	{
		total1 = 0;
		for (j = 0; j < 4; j++)
		{
			total1 += score[i][j];
		}
		avg1 = total1 / 4.0;
		printf("%c의 총 점수 : %d, 평균 : %.1lf\n", stu, total1, avg1);
		stu++;

	}

	printf("\n");

	for (j = 0; j < 4; j++)
	{
		total2 = 0;

		for (i = 0; i < 5; i++)
		{
			total2 += score[i][j];
		}

		avg2 = total2 / 5.0;

		printf("%d과목 총 점수 : %d, 평균 : %.1lf\n", j + 1, total2, avg2);
	}

	return 0;
}
```
![결과8](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EC%B4%9D%ED%95%A9%ED%8F%89%EA%B7%A0.png "총합평균")   
---

포인터 배열 : 포인터 또한 변수이므로 그 포인터를 여러개 가진 배열도 만들 수 있다.   
```C
int main()
{
	char* pary[5];
	int i;

	// 각 포인터 변수에 문자열 상수의 첫 번째 문자 주소 저장
	pary[0] = "dog";
	pary[1] = "elephant";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion";

	for (i = 0; i < 5; i++)
	{
		printf("%s\n", pary[i]);
	}

	return 0;
}
```
2차원으로 활용하고자 할 때
```C
int main()
{
	int ary1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ary2[4] = { 11, 12, 13, 14 };
	int ary3[4] = { 21, 22, 23, 24 };
	int* pary[3] = { ary1, ary2, ary3 };
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%5d", pary[i][j]);
		}
		printf("\n");
	}
	printf("%5d", pary[2][2]);
	return 0;
}
```
![결과9](https://github.com/HongryeolSeong/StudyC21/blob/main/img/res1.png "2차원배열")
<br>

---
_14장 퀴즈   
단어의 회문 테스트_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int flag = 0;
	char str[30];
	int size;
	

	while (1)
	{
		printf("테스트할 단어를 입력하시오. : ");
		scanf("%s", str);
		size = strlen(str);
		printf("배열사이즈는 : %d\n", size);

		char* pa = str;
		char* pb = str + (size - 1);

		for (i = 0; i < size/2; i++)
		{
			if (*pa != *pb)
			{
				flag = -1;
				break;
			}
			else if (*pa == *pb)
			{
				pa++;
				pb--;
			}
			flag = 1;
		}

		if (flag == -1)
		{
			printf("이 단어는 회문이 아닙니다.\n");
		}
		else if (flag == 1)
		{
			printf("이 단어는 회문입니다!!!\n");
		}
	}

	return 0;
}
```
![결과10](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%9A%8C%EB%AC%B8.png "회문")
<br>
<br>
<br>

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
   
* '배열' 주소와 배열 '요소'의 주소   
int ary[5]의 경우   
ary + 1 => 1234 + (1 * sizeof(ary[0]) => 1234 + (1 * 4) => 1238   
ary + 1 => 1234 + (1 * sizeof(ary) => 1234 + (1 * 20) => 1254   
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
<br>
<br>

## Chapter_16 메모리 동적 할당🎯

선언을 통해 저장 공간을 미리 확보할 수 있지만, 때로는 프로그램 실행 중에 저장 공간을 할당할 수 있어야 한다.   

* malloc과 free 함수   
stdlib.h 헤더 인클루드 후 사용 가능   
```C
int main()
{
	int* pi; // 동적 할당 영역을 연결할 포인터 pi

	pi = (int *)malloc(sizeof(int)); // 동적 메모리 할당
	if (pi == NULL) // 동적 할당 실패시 = 포인터가 NULL 반환시
	{
		printf("# 메모리가 부족합니다.\n");
		exit(1); // 프로그램 종료
	}

	*pi = 10;
	
	free(pi); // 동적 메모리 반환
}
```
위처럼 malloc()으로 영역을 동적 할당 후 free()로 해당 영역을 반환해야한다   
<br>

* 동적 할당 영역을 배열로 활용   
할당된 공간의 시작위치를 포인터로 연결시 해당 공간을 배열로 사용 가능.   
```C
int main()
{
	int* pi;
	int i, sum = 0; // sum은 연산시 처음 값이 쓰레기 값이면 안되므로 0으로 초기화
	pi = (int*)malloc(5 * sizeof(int));
	if (pi == NULL)
	{
		printf("메모리가 부족합니다!\n");
		exit(1);
	}
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &pi[i]); // 메모리를 배열처럼 사용
		sum += pi[i];
	}
	free(pi);
}
```
<br>

* calloc, realloc 함수   
calloc() : 메모리 할당시 공간을 0으로 초기화   
realloc() : 이미 동적 할당된 공간의 크기를 조절   
realloc() 유의점   
-> 공간 부족시 새 메모리 공간 할당하여 기존 요소 복사   
-> but null이 반환될 시 기존 주소 잃어버림   
--> 임시 포인터에 realloc 공간 반환 후 사용할 것   
```C
int main()
{
	int* pi; // 동적 할당 공간과 연결할 포인터
	int* pi_back; // realloc 오류를 대비한 백업 포인터

	pi = (int*)calloc(size, sizeof(int)); // 5개 공간 할당 후 자동으로 0으로 초기화
	while (1)
	{
		if (count == size) // 저장 공간 모두 사용시
		{
			size += 5; // 공간 크기 늘려서
			pi_back = pi; // 할당 실패 방지 pi의 공간 주소를 pi_back으로 백업
			pi = (int*)realloc(pi, size * sizeof(int)); // 재할당
			if (pi == NULL) // 공간 할당 실패시
			{
				pi = pi_back; // 백업했던 공간의 주소를 다시 기존 pi포인터와 연결
			}
		}
	}
	
	for (i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi);
}
```
위처럼 pi의 백업 포인터인 pi_back을 활용하여 realloc의 할당 실패를 방지하였다.   
<br>

* 동적 할당 활용한 문자열 처리   
동적 할당을 통해 효율적인 문자열 저장 공간 관리   
```C
int main()
{
	char temp[80]; // 임시 문자열 배열
	char* str[3]; // 최종 문자열 배열
	int i;

	for (i = 0; i < 3; i++)
	{
		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1); // 임시 배열 길이에 + 1 하여 널문자까지 입력되게 함
		strcpy(str[i], temp); // 동적 할당 된 임시 배열을 최종 배열인 str에 복사
	}

	for (i = 0; i < 3; i++) // 동적 할당된 문자열 배열의 공간을 해제
	{
		free(str[i]);
		printf("할당된 메모리가 반환되었습니다.\n");
	}
}
```
<br>
<br>

## Chapter_17 사용자 정의 자료형🎯

* 구조체 : int, char, 배열 등 여러 자료형을 묶어서 사용 가능한 복합 자료형   
```C
#include <stdio.h>

struct student // 메모리 할당x
{
	int num;
	double grade;
}; // ; 필수

int main()
{
	struct student s1; // 구조체 변수 생성 동시에 메모리 할당 됨

	s1.num = 2;
	s1.grade = 2.7;
}
```
<br>

* 다른 구조체를 멤버로 갖는 구조체 사용시   
```c
struct profile
{
	int age;
	double height;
};

struct student
{
	struct profile pf;
};

int main()
{
	struct student yuni;

	yuni.pf.age = 17;
	yuni.pf.height = 164.5;
}
```
<br>

* 구조체 변수의 초기화와 대입 연산   
```C
struct student
{
	int id;
	char name[20];
	double grade;
};

int main()
{
	struct student s1 = { 315, "홍길동", 2.4 }, // 구조체 변수의 초기화
		       s2 = { 316, "이순신", 3.7 },
		       s3 = { 317, "세종대왕", 4.4 };

	struct student max; // 대입 시킬 구조체 변수

	max = s1; // 한 구조체 변수에 다른 구조체 변수를 대입
	if (s2.grade > max.grade) max = s2;
	if (s3.grade > max.grade) max = s3;
}
```
<br>

* 구조체를 매개변수로 하는 함수
```C
struct vision
{
	double left;
	double right;
};

struct vision exchange(struct vision robot);

int main()
{
	struct vision robot;

	scanf("%lf%lf", &(robot.left), &(robot.right));
	robot = exchange(robot);
}

struct vision exchange(struct vision robot) { 교체 실행문; }
```
<br>

* 구조체 포인터
```C
struct score
{
	int kor;
	int math;
};

int main()
{
	struct score yuni = { 90, 80 };
	struct score* ps = &yuni; // 구조체 변수 yuni의 주소를 담는 포인터 ps.

	printf("국어 : %d\n", (*ps).kor); // *의 참조 연산이 우선 순위이므로 괄호 필수
	printf("영어 : %d\n", ps->eng); // 위와 동일한 결과 출력
}
```
<br>

* 구조체 배열
```C
int main()
{
	struct address list[5] = {
		{"홍길동", 23, "111-1111", "울릉도 독도"}, // address 구조체의 변수인 list배열의 초기화
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고", 19, "333-3333", "완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555", "황해도 해주"}
	};

	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n",
			list[i].name, list[i].age, list[i].tel, list[i].addr);
	}
}
```
위의 구조체를 매개변수로 넘긴 출력 함수 활용시
```C
void print_list(struct address* lp) // 구조체 변수인 list[5]를 포인터로 넘겨 받음
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n",
			(*(lp + i)).name, (*(lp + i)).age, (*(lp + i)).tel, (*(lp + i)).addr);
			//(lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr); // 위와 동일한 결과 출력
	}
}
```
<br>

* 자기 참조 구조체   
자신의 구조체를 가르키는 포인터 선언을 통해 여러 구조체 변수가 연결된 형태 구현 가능
```C
struct list
{
	int num;
	struct list* next; // 구조체 자신을 가리키는 포인터 next
};

int main()
{
	struct list a = { 10, 0 }, b = { 20, 0 }, c = { 30, 0 };
	struct list* head = &a, * current;
	// 구조체 a를 가르키는 head와 list구조체를 가르키는 current 포인터

	a.next = &b; // next포인터로 구조체들을 연결
	b.next = &c;

	printf("head->num : %d\n", head->num);
	printf("head->next->num : %d\n", head->next->num);

	printf("list all : ");
	current = head;
	while (current != NULL) // 연결 리스트 구조
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

	return 0;
}
```
<br>

* 공용체   
구조체와 비슷하지만 모든 멤버가 하나의 저장 공간을 같이 사용   
효율적 메모리 활용이 중요한 임베디드에서 많이 활용   
```C
union student
{
	int num;
	double grade;
};

struct student1
{
	int num;
	double grade;
};

int main()
{
	union student s1 = { 315 }; // 이렇게 하면 공용체는 첫 번째 멤버만 초기화 됨

	printf("학번 : %d\n", s1.num);
	s1.grade = 4.4;
	printf("학점 : %.1lf\n", s1.grade);

	printf("학번 : %d\n", s1.num); // 이렇게 하면 겹쳐져서 이상한 값 나옴

	s1.num = 315; // 그러므로 다시 대입 후 
	printf("학번 : %d\n", s1.num); // 출력해야함
	
	printf("공용체 크기 : %d\n", sizeof(s1));
	// 공용체는 제일 큰 멤버 변수의 크기만을 할당받아 사용 그리고 멤버 끼리 공유

	struct student1 s2;
	
	printf("구조체 크기 : %d\n", sizeof(s2)); // 12byte + 패딩바이트
}
```
<br>

* 열거형   
역시 구조체와 비슷하지만 멤버들이 정수로 정의됨.   
```C
enum season { SPRING, SUMMER, FALL, WINTER };

int main()
{
	enum season ss;
	char* pc = NULL;

	scanf("%d", &ss); // 정수값 입력

	switch (ss)
	{
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "swimming";
		break;
	case FALL:
		pc = "trip";
		break;
	case WINTER:
		pc = "skiing";
		break;
	}

	printf("나의 레저 활동 => %s\n", pc);
	printf("%d %d %d %d\n", SPRING, SUMMER, FALL, WINTER);
	// enum의 멤버는 정수값을 가진다. 이웃 멤버와 +1 관계 가짐
	// if FALL = 100 이면 SUMMER = 1, WINTER = 101 이 된다.

	return 0;
}
```
<br>

* typedef   
구조체, 공용체, 열거형의 변수 생성시 예약어를 생략하게 해주는 형 재정의   
```C
typedef struct {
	int num;
	double grade;
}Student;

void print_data(Student* ps);

int main()
{
	Student s1 = { 315, 4.2 };

	print_data(&s1);

	return 0;
}

void print_data(Student* ps)
{
	printf("학번 : %d\n", ps->num);
	printf("학점 : %.1lf\n", ps->grade);
}
```
   
---
_17장 퀴즈   
5명 사원의 아이디, 이름, 급여 입력 후 총/평균 급여 구하기_
```C
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

		// 구조체 멤버인 name을 동적 할당하는 과정
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

	for (i = 0; i < 5; i++) // 동적 할당된 메모리 반환
	{
		free(list[i].name);
	}
}
```
<br>
<br>

## Chapter_18 파일 입출력🎯

C의 다양한 파일 입출력 함수를 활용하여 일회성 데이터가 아닌 데이터 다루기   
   
* 파일 개방 및 폐쇄
파일에 데이터 입/출력하기 전 준비 단계.   
fopen과 fclose 함수를 이용함.   
[개방 모드 정리](https://bite-sized-learning.tistory.com/318 "모드참고")
```C
int main()
{
	FILE* fp; // 파일 구조체를 가리키는 포인터

	// 파일 개방
	// fopen()이 파일은 찾는 기본 위치는 "현재 작업 디렉터리"
	fp = fopen("a.txt", "r"); // 파일 정보가 담긴 스트림 파일의 버퍼의 주소를 담는 fp
	if (fp == NULL) // 파일이 없는 경우 = 주소가 NULL
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1; // 프로그램 종료
	}
	printf("파일이 열렸습니다.\n");

	// 파일 폐쇄
	fclose(fp);
}
```   
fopen()과는 다르게 fclose()는 오류 발생시 EOF(= -1)을 반환한다.

<br>

* 스트림 파일과 FILE 구조체   
스트림 파일은 프로그램과 입출력 장치 사이의 다리 역할   
1. 스트림 파일은 메모리에 버퍼와 FILE 구조체를 둔다
2. 버퍼의 상태를 파악하여 FILE 구조체 변수에 저장한다
3. 프로그램에 FILE 변수의 주소를 반환하여 파일의 정보를 읽거나 입출력이 되게 한다   
<br>

* fgetc
파일 개방 후 파일 내 데이터 읽어오기   
![결과11](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%9A%8C%EB%AC%B8.png "fileres1")
```C
int main()
{
	FILE* fp;
	int ch;

	fp = fopen("a.txt", "r"); // 읽기 개방 모드
	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp); // 파일에서 문자 하나씩 읽어오기
		if (ch == EOF) // 더 이상 읽을 문자가 없는 경우
		{
			break;
		}
		putchar(ch); // 버퍼에 저장된 문자를 화면에 출력
	}
	fclose(fp);
}
```   
![결과12](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%9A%8C%EB%AC%B8.png "fileres2")
<br>

* fputc   
파일 개방 후 파일에 데이터 출력하기   
```C
int main()
{
	FILE* fp;
	char str[] = "banana";
	int i;

	// 파일 개방 - 쓰기 모드
	fp = fopen("b.txt", "w"); // b.txt가 없는 경우 새로 만듦
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	// 파일에 str 출력
	i = 0;
	while (str[i] != '\0') // 널문자를 만날때 까지
	{
		fputc(str[i], fp); // b.txt에 str을 출력
		i++;
	}
	fputc('\n', fp); // 마지막에 개행 문자 대입
	fclose(fp);
}
```   
![결과13](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%9A%8C%EB%AC%B8.png "fileres3")
<br>

* 기본적으로 개방되는 표준 입출력 스트림 파일   
이 파일들을 이용하여 파일 포인터 없이 사용토록 함.   
stdin 표준 입력 스트림 키보드     
stdout 표준 출력 스트림 모니터   
stderr 표준 에러 스트림 모니터   
```C
int main()
{
	int ch;

	while (1)
	{
		// 예제 1. getchar()는 함수 내부적으로 stdin사용
		ch = getchar(); // 파일 포인터 사용x

		// 예제 2. 파일 포인터로 stdin을 받아 사용하는 fgetc()
		//ch = fgetc(stdin);

		if (ch == EOF)
		{
			break;
		}

		// 예제1. putchar()는 함수 내부적으로 stdout사용
		putchar(ch); // 파일 포인터 사용x

		// 예제 2. 파일 포인터로 stdout을 받아 사용하는 fputc()
		//fputc(ch, stdout);
	}
}
```   
위와 같이 표준 스트림 파일을 활용하여 따로 파일 포인터를 생성하지 않고   
키보드로 입력받고 모니터에 출력할 수 있음을 볼 수 있다.   
<br>

* 텍스트 / 바이너리 파일   
파일은 텍스트 파일과 바이너리 파일로 분류됨.   
아스키 코드값에 따라 읽거나 저장 시 -> 텍스트 파일 -> 개방 모드는 기존과 동일 or 't' 붙일 것   
그 외 -> 바이너리 파일 -> 개방 모드는 기존에 'b'를 붙일 것   
```C
int main()
{
	FILE* fp;
	// 10개의 아스키 문자
	int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	int i, res;

	// 아스키 문자들을 바이너리방식으로 a.txt에 출력
	fp = fopen("a.txt", "wb");
	for (i = 0; i < 10; i++)
	{
		fputc(ary[i], fp);
	}
	fclose(fp);

	// a.txt를 텍스트 파일로 읽어오기
	fp = fopen("a.txt", "rt");
	while (1)
	{
		res = fgetc(fp);
		if (res == EOF) break; // 아스키 코드 26 = -1 = EOF = ^Z
		printf("%4d", res);
	}
	fclose(fp);
}
```   
![결과14](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%9A%8C%EB%AC%B8.png "fileres4")   
위처럼 파일 형태와 개방 모드가 다를시 26을 아스키 코드로 읽어 EOF로 판단하여   
26 전에 있는 요소들만 읽게됨   
<br>

* + 개방모드, 여러가지 파일 함수
기존 개방 모드에 '+'를 붙이면 프로그램 실행 중에 읽고 쓰고가 가능해짐   
fseek(FILE * Stream, long offset, int whence); : whence를 기준 offset만큼 파일의 버퍼에서 위치 지시사를 이동   
SEEK_SET : 파일의 처음 : 양수만 가능
SEEK_CUR : 파일의 현재 위치 : 양수와 음수 가능
SEEK_SET : 파일의 끝 : 음수만 가능
rewind(FILE * Stream); = fseek(FILE * Stream, 0, SEEK_SET);   
feof(FILE * Stream); : 스트림 파일의 데이터를 모두 읽었는지 판단.   
파일의 끝 -> 0이 아닌 값
파일의 끝x -> 0   
```C
int main()
{
	FILE* fp;
	char str[20];

	// a -> 파일 끝에 추가
	// + -> 데이터 기록 중 언제든지 파일 내용 읽을 수 있게함
	fp = fopen("a.txt", "a+");
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		printf("과일 이름 : ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0) // 경우 1. end 입력시 종료
		{
			break;
		}
		else if (strcmp(str, "list") == 0) // 경우 2. list 입력시 파일 내용 확인
		{
			fseek(fp, 0, SEEK_SET); // 버퍼의 위치 지시자를 맨 첨으로 이동
			while (1)
			{
				fgets(str, sizeof(str), fp); // 파일 내용 읽음
				if (feof(fp)) // 파일 내용 다 읽으면 종료
				{
					break;
				}
				printf("%s", str);
			}
		}
		else // 경우 3. 과일 입력시
		{
			fprintf(fp, "%s\n", str); // 입력한 과일을 파일에 출력
		}
	}
	fclose(fp);
}
```   
<br>

* fgets, fputs   
파일에 데이터를 한 줄씩("ABCD" + "\n")입력 또는 출력시 사용   

