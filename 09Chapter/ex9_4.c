#include <stdio.h>

int main()
{
	int a = 10, b = 20;
	const int* pa = &a; // �����Ͱ� ����Ű�� ���� �����͸� ���ȭ, pa ���������� a�� �� �ٲٰ��ϴ� ���
	int* const pb = &b; // ������ ��ü�� ���ȭ

	printf("���� a �� : %d\n", *pa);
	pa = &b;
	printf("���� b �� : %d\n", *pa);
	pa = &a;
	a = 20;
	printf("������ a �� : %d\n", *pa);
	//*pa = 30; // �Ұ�
	//printf("������ a �� : %d\n", *pa);
	*pb = 10;
	printf("���� b �� : %d\n", *pb);
	//pb = &a; // �Ұ�

	return 0;
}