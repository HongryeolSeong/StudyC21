#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a;
	char b;

	//���� ���� ���ڸ� �Է¹޴°��
	printf("���� �ϳ��� �Է��ϼ��� : ");
	scanf("%d", &a);
	//getchar(); // ���ۿ� �ִ� �����ϳ��� �ҷ���
	printf("���� �ϳ��� �Է��ϼ��� : ");
	scanf(" %c", &b); // getchar�Ⱦ��� " %c"�ᵵ ����

	printf("�Էµ� ���� %d, %c �Դϴ�.\n", a, b);
	
	return 0;
}