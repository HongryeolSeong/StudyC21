#include <stdio.h>
#define SUM(a, b) ((a) + (b))
#define MUL(a, b) ((a) * (b))
#define test(a) (a * 10)

int main()
{
	int a = 10, b = 20;
	int x = 30, y = 40;
	int res;

	printf("a + b = %d\n", SUM(a, b));
	printf("x + y = %d\n", SUM(x, y));
	res = 30 / MUL(2, 5);
	printf("res : %d\n", res);
	
	printf("%d\n", test(a + 10)); 
	// 원래 200 나와야 하지만 110출력
	// -> #define test(a) ((a) * (10))이 되야함

	return 0;
}