#include <stdio.h>

int main()
{
	int a = 10;
	int b = 10;
	int c = 10;
	int d = 20;

	++a; // 전위
	--b; // 전위
	c++; // 후위 : 실행 후 증감 처리
	d--; // 후위

	printf("a : %d\n", a);
	printf("b : %d\n", b);
	printf("c : %d\n", c);
	printf("d : %d", d);


	return 0;
}