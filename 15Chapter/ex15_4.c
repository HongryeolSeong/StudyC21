#include <stdio.h>

int main()
{
	int ary[5];

	printf("  ary의 값 : %u\t", ary);
	printf("ary의 주소 : %u\n", &ary);
	printf("   ary + 1 : %u\t", ary + 1); // 배열 한 요소의 주소 + 1
	printf("  &ary + 1 : %u\n", &ary + 1); // 전체 배열 주소 + 1

	return 0;
}