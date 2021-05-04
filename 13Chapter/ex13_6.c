#include <stdio.h>

void add_ten(int a);

int main()
{
	int a = 10;

	add_ten(a); // main의 a값을 복사하여 add_ten으로 전달
	printf("a : %d\n", a);

	return 0;
}

void add_ten(int a) // != main의 a. a의 값만 전달 받음
{
	a = a + 10;
}