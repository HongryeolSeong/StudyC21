#include <stdio.h>

int main()
{
	int a = 10;
	int* pa = &a;

	printf("%p %p\n", &a, pa);

	printf("1차 int 배열=================================\n");
	int ary1[4] = { 1, 2 };
	int* pary1 = ary1;
	//int (*pary1) = ary1; // 배열 포인터 사용시 결과 동. 1차원 배열의 경우 괄호 생략가능
	//char* pary1 = ary1; // 다른 자료형으로 포인터 배열 선언가능하지만
	printf("%p %p\n", ary1, pary1);
	printf("%p %p\n", ary1 + 1, pary1 + 1); // 주소는 달라짐

	printf("1차 char 배열=================================\n");
	char ary2[2] = { 'b', 'c' };
	char* pary2 = ary2;
	//int* pary2 = ary2;
	printf("%p %p\n", ary2, pary2);
	printf("%p %p\n", ary2 + 1, pary2 + 1);

	printf("2차원 배열=================================\n");
	int ary3[][2] = { {1, 2}, {3, 4} };
	//int* pary3 = ary3; // 0번방의 첫 요소의 주소 가리킴
	int (* pary3)[2] = ary3; // 배열 포인터. ary3의 첫 1차원 배열의 주소를 가리킴
	printf("%p %p\n", ary3, pary3);
	printf("%p %p\n", ary3 + 1, pary3 + 1);

	printf("포인터 배열=================================\n");
	char* ary4[10] = { "hi", "good" }; // 포인터 배열
	//char* pary4 = ary4;
	char** pary4 = ary4; // ary4의 0번방 주소 가리킴
	printf("%p %p\n", ary4, pary4);
	printf("%p %p\n", ary4 + 1, pary4 + 1);

	return 0;
}