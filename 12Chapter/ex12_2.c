#include <stdio.h>

int main()
{
	char* dessert = "apple";

	printf("���� �Ľ��� %s�Դϴ�.\n", dessert);
	dessert = "banana"; // banana �� ���� ������ �Ұ�
	printf("���� �Ľ��� %s�Դϴ�.\n", dessert);

	return 0;
}