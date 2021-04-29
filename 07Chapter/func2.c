// 입력과 출력이 없는 함수 정의
#include <stdio.h>

void func(); // 함수 원형(선언) -> main 밑에 함수 정의한 경우

int main()
{
	func(); // func 함수 호출
	return 0;
}

void func() 
{
	int a = 10, b = 20;
	int res;

	res = a + b;
	printf("res = %d", res);
}