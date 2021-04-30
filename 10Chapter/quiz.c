#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_ary(int* pa, int size);
void swap_ary(int* pa, int size);
void print_ary(int* pa, int size);

int main()
{
	int ary[10];
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	swap_ary(ary, size);
	print_ary(ary, size);

	return 0;
}

void input_ary(int* pa, int size)
{
	int i;

	printf("%d개의 정수값 입력 : ", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", pa + i);
	}
}

void swap_ary(int* pa, int size)
{
	int temp, i;
	int* px = pa;
	int* py = pa + 9;

	for (i = 0; i < 10; i++)
	{
		temp = *(px + i);
		*(px + i) = *(py - i);
		*(py - i) = temp;
	}

	/*temp = *(px + 2);
	*(px + 2) = *(py - 2);
	*(py - 2) = temp;*/
}

void print_ary(int* pa, int size)
{
	int i;

	printf("배열 출력\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
}
