#include <stdio.h>

int main()
{
	int income = 0;
	double tax;
	const double tax_rate = 0.12;
	//tax_rate = 0.15; // 상수는 변경 불가

	income = 456;
	tax = income * tax_rate;
	printf("세금은 : %.1lf입니다.\n", tax);

	return 0;
}