#include <stdio.h>

int main()
{
	int a = 10, b = 20, res;

	// 삼항 연산자
	res = (a > b) ? a : b;
	printf("큰 값 : %d\n", res);

	return 0;
}
