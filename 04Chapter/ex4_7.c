#include <stdio.h>

int main()
{
	int a = 10, b = 20, res;

	a + b; // ������ ������ �����Ƿ� ���ǹ��� ����
	printf("%d + %d = %d\n", a, b, a + b);

	res = a + b;
	printf("%d + %d = %d\n", a, b, res);

	/*double c = 4.8, d = 2.3;
	res = c % d; // �Ǽ��� ������ ���� �Ұ�
	printf("%lf", res);*/

	return 0;
}