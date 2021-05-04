#include <stdio.h>

int main()
{
	char* pary[5];
	int i;

	// 각 포인터 변수에 문자열 상수의 첫 번째 문자 주소 저장
	pary[0] = "dog";
	pary[1] = "elephant";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion";

	for (i = 0; i < 5; i++)
	{
		printf("%s\n", pary[i]);
	}

	return 0;
}