#include <stdio.h>
#define VER 7
#define BIT16

int main()
{
	int max;

#if VER >=6;
	printf("버전 %d입니다.\n", VER);
#endif

#ifdef BIT16 // 매크로명 BIT16이 정의 돼있다면
	max = 32767;
#else // 안돼있다면 = #ifndef
	max = 2147483647;
#endif

	printf("int형 변수의 최댓값 : %d\n", max);

	return 0;
}