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
-> 배열 입력시 &붙이지 말 것<br>
<br>
_3장 퀴즈<br>
정수 다음 바로 문자 입력해야할 경우_<br>
```
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
