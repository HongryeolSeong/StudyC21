#include <stdio.h>

int main()
{
	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b); // 자동 형 변환으로 a만 double 해도 됨
	printf("a = %d, b = %d\n", a, b);
	printf("a / b의 결과 : %.1lf\n", res);

	a = (int)res;
	printf("(int)%.1lf의 결과 : %d\n", res, a);

	// 좌항은 형 변환 불가
	return 0;
}