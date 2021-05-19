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
