#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* pi;
	int* pi_back; // realloc 오류를 대비한 백업 포인터
	int size = 5;
	int count = 0;
	int num;
	int i;

	pi = (int*)calloc(size, sizeof(int)); // 5개 공간 할당 후 자동으로 0으로 초기화
	while (1)
	{
		printf("양수만 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0) break;
		if (count == size) // 저장 공간 5개 모두 사용시
		{
			size += 5; // 공간 크기 늘려서
			pi_back = pi;
			pi = (int*)realloc(pi, size * sizeof(int)); // 재할당

			if (pi == NULL)
			{
				pi = pi_back;
			}
		}
		pi[count++] = num;
	}
	for (i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi);

	return 0;
}