#include <stdio.h>

int main()
{
	int a = 10;
	int* pa = &a;

	printf("%p %p\n", &a, pa);

	printf("1�� int �迭=================================\n");
	int ary1[4] = { 1, 2 };
	int* pary1 = ary1;
	//int (*pary1) = ary1; // �迭 ������ ���� ��� ��. 1���� �迭�� ��� ��ȣ ��������
	//char* pary1 = ary1; // �ٸ� �ڷ������� ������ �迭 ���𰡴�������
	printf("%p %p\n", ary1, pary1);
	printf("%p %p\n", ary1 + 1, pary1 + 1); // �ּҴ� �޶���

	printf("1�� char �迭=================================\n");
	char ary2[2] = { 'b', 'c' };
	char* pary2 = ary2;
	//int* pary2 = ary2;
	printf("%p %p\n", ary2, pary2);
	printf("%p %p\n", ary2 + 1, pary2 + 1);

	printf("2���� �迭=================================\n");
	int ary3[][2] = { {1, 2}, {3, 4} };
	//int* pary3 = ary3; // 0������ ù ����� �ּ� ����Ŵ
	int (* pary3)[2] = ary3; // �迭 ������. ary3�� ù 1���� �迭�� �ּҸ� ����Ŵ
	printf("%p %p\n", ary3, pary3);
	printf("%p %p\n", ary3 + 1, pary3 + 1);

	printf("������ �迭=================================\n");
	char* ary4[10] = { "hi", "good" }; // ������ �迭
	//char* pary4 = ary4;
	char** pary4 = ary4; // ary4�� 0���� �ּ� ����Ŵ
	printf("%p %p\n", ary4, pary4);
	printf("%p %p\n", ary4 + 1, pary4 + 1);

	return 0;
}