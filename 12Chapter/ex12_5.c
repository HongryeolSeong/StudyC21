#include <stdio.h>

int main()
{
	char str[80];

	printf("������ ���Ե� ���ڿ� �Է� : ");
	fgets(str, sizeof(str), stdin); // Ű����� �Է��Ҷ� stdin(��Ʈ��)

	printf("�Էµ� ���ڿ��� %s�Դϴ�.\n", str);

	return 0;
}