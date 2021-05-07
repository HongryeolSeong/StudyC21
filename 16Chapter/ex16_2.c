#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* pi;
	int i, sum = 0; // sum은 연산해야하므로 처음에 쓰레기 값이 있으면 안됨

	pi = (int*)malloc(5 * sizeof(int));
	if (pi == NULL)
	{
		printf("메모리가 부족합니다!\n");
		exit(1);
	}

	printf("다섯 명의 나이를 입력하세요 : ");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &pi[i]); // 메모리를 배열처럼 사용
		sum += pi[i];
	}

	printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));

	free(pi);

	return 0;
}