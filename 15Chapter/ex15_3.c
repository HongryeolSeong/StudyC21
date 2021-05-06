#include <stdio.h>

void print_str(char** pps, int cnt);

int main()
{
	char* ptr_ary[] = { "eagle", "tiger", "lion", "squirrel" };
	// 1차원 배열이지만 포인터 배열이므로 이중 포인터로 넘겨 받을 것
	int count;

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
	print_str(ptr_ary, count);

	return 0;
}

void print_str(char** pps, int cnt)
{
	int i;

	for (i = 0; i < cnt; i++)
	{
		printf("%s\n", pps[i]);
	}
}