// �Է°� ����� ���� �Լ� ����
#include <stdio.h>

void func(); // �Լ� ����(����) -> main �ؿ� �Լ� ������ ���

int main()
{
	func(); // func �Լ� ȣ��
	return 0;
}

void func() 
{
	int a = 10, b = 20;
	int res;

	res = a + b;
	printf("res = %d", res);
}