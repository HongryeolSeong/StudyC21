#include <stdio.h>

int main()
{
	int ary[5];

	printf("  ary�� �� : %u\t", ary);
	printf("ary�� �ּ� : %u\n", &ary);
	printf("   ary + 1 : %u\t", ary + 1); // �迭 �� ����� �ּ� + 1
	printf("  &ary + 1 : %u\n", &ary + 1); // ��ü �迭 �ּ� + 1

	return 0;
}