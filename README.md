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
![결과8](https://github.com/HongryeolSeong/StudyC21/blob/main/img/res1.png "2차원배열")
<br>
<br>

## Chapter_15 응용 포인터🎯
