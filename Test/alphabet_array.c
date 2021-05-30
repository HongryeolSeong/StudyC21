#include <stdio.h>
#include <stdlib.h>

void Print_ary(char* pary, int sz);
void Sort_ary(char* pary, int sz);

int main()
{
	char input_ary[10];
	char lower_ary[10];
	char upper_ary[10];
	int i;
	int szu = 0;
	int szl = 0;

	gets(input_ary);

	for (i = 0; i < strlen(input_ary); i++)
	{
		if (input_ary[i] >= 'A' && input_ary[i] <= 'Z')
		{
			upper_ary[szu] = input_ary[i];
			szu++;
		}
		else if (input_ary[i] >= 'a' && input_ary[i] <= 'z')
		{
			lower_ary[szl] = input_ary[i];
			szl++;
		}
	}

	// 대소문자 배열에 요소 삽입 후 마지막 요소로 널문자 삽입
	upper_ary[szu] = '\0';
	lower_ary[szl] = '\0';

	Print_ary(upper_ary, szu);
	printf("\n");
	Print_ary(lower_ary, szl);
	printf("\n");

	Sort_ary(upper_ary, szu);
	Sort_ary(lower_ary, szl);

	Print_ary(upper_ary, szu);
	printf("\n");
	Print_ary(lower_ary, szl);

	return 0;
}

void Print_ary(char* pary, int sz)
{
	int i;
	
	for (i = 0; i < sz; i++)
	{
		printf("%c", pary[i]);
	}
}

void Sort_ary(char* pary, int sz)
{
	int i, j, temp;

	for (i = 1; i < sz; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (pary[j] < pary[j -1])
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
}