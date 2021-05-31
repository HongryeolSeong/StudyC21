// 대소문자 분류_배열
#include <stdio.h>
#include <stdlib.h>

void Print_ary(char* pary, int sz);		// 배열 출력 함수
void Sort_ary(char* pary, int sz);		// 배열 정렬 함수

int main()
{
	char input_ary[10];					// 입력된 알파벳을 담는 배열
	char upper_ary[10];					// 입력된 알파벳 중 대문자를 담는 배열
	char lower_ary[10];					// 입력된 알파벳 중 소문자를 담는 배열
	int i;
	int szu = 0;						// upper배열의 사이즈
	int szl = 0;						// lower배열의 사이즈

	// 1. 알파벳 입력
	gets(input_ary);

	// 2. 대소문자 분류
	for (i = 0; i < strlen(input_ary); i++)
	{
		if (input_ary[i] >= 'A' && input_ary[i] <= 'Z')
		{
			upper_ary[szu] = input_ary[i];
			szu++; // 분류하여 upper배열에 삽입할 때 마다 증가
		}
		else if (input_ary[i] >= 'a' && input_ary[i] <= 'z')
		{
			lower_ary[szl] = input_ary[i];
			szl++; // 분류하여 lower배열에 삽입할 때 마다 증가
		}
	}

	// 3. 대소문자 배열에 요소 삽입 후 마지막 요소로 널문자 삽입
	upper_ary[szu] = '\0';
	lower_ary[szl] = '\0';

	// 4. 대소문자 분류 결과 출력
	Print_ary(upper_ary, szu);
	printf("\n");
	Print_ary(lower_ary, szl);
	printf("\n");

	// 5. 각 배열에 정렬 수행
	Sort_ary(upper_ary, szu);
	Sort_ary(lower_ary, szl);

	// 6. 결과 확인
	Print_ary(upper_ary, szu);
	printf("\n");
	Print_ary(lower_ary, szl);

	return 0;
}

// 배열 출력
void Print_ary(char* pary, int sz)
{
	int i;
	
	for (i = 0; i < sz; i++)
	{
		printf("%c", pary[i]);
	}
}

// 배열 정렬
void Sort_ary(char* pary, int sz)
{
	int i, j, temp;

	// 삽입 정렬
	for (i = 1; i < sz; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (pary[j] < pary[j - 1]) // 앞 요소와 비교했을 때 작은 경우
			{
				// swap 실행
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
}