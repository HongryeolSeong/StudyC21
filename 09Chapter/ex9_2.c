#include <stdio.h>

int main()
{
	int a;
	int* pa; // 요기서 *는 그냥 포인터임을 나타내는 표시

	pa = &a; // 포인터에 a의 주소 저장
	*pa = 10; // 요기서 *는 포인터의 주소에 저장된 데이터를 나타냄

	printf("포인터로 a 값 출력 : %d\n", *pa);
	printf("변수명으로 a 값 출력 : %d\n", a);

	return 0;
}