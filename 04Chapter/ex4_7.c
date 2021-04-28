#include <stdio.h>

int main()
{
	int a = 10, b = 20, res;

	a + b; // 저장할 변수가 없으므로 무의미한 연산
	printf("%d + %d = %d\n", a, b, a + b);

	res = a + b;
	printf("%d + %d = %d\n", a, b, res);

	/*double c = 4.8, d = 2.3;
	res = c % d; // 실수는 나머지 연산 불가
	printf("%lf", res);*/

	return 0;
}