#include <stdio.h>
#pragma pack(push, 1) // #pragma pack(1)도 가능
// 바이트 얼라인먼트를 1로 바꿈
// -> 단위 크기를 1로 설정 -> 구조체 멤버가 모든 위치에 할당
// -> 이후 정의된 구조체는 모두 패딩바이트 포함x
// -> 구초제의 크기는 멤버들의 크기를 더한 것과 같다
typedef struct
{
	char ch;
	int in;
} Sample1;

// 바꾸기 전의 바이트 얼라인먼트 규칙을 적용 시
#pragma pack(pop)
typedef struct
{
	char ch;
	int in;
} Sample2;

int main()
{
	printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
	printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));

	return 0;
}