#include <stdio.h>

int main()
{
	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b); // �ڵ� �� ��ȯ���� a�� double �ص� ��
	printf("a = %d, b = %d\n", a, b);
	printf("a / b�� ��� : %.1lf\n", res);

	a = (int)res;
	printf("(int)%.1lf�� ��� : %d\n", res, a);

	// ������ �� ��ȯ �Ұ�
	return 0;
}