#include <stdio.h>
#define VER 7
#define BIT16

int main()
{
	int max;

#if VER >=6;
	printf("���� %d�Դϴ�.\n", VER);
#endif

#ifdef BIT16 // ��ũ�θ� BIT16�� ���� ���ִٸ�
	max = 32767;
#else // �ȵ��ִٸ� = #ifndef
	max = 2147483647;
#endif

	printf("int�� ������ �ִ� : %d\n", max);

	return 0;
}