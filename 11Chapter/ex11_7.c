#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num, grade;

	//printf("���� �Է� : ");
	//grade = getchar();
	//printf("�й� �Է� : ");
	//scanf("%d", &num); // ���������͸� ã���Ƿ� �ڵ����� ���๮�ڴ� �н�
	////getchar();
	//printf("�й� : %d, ���� : %c", num, grade);

	
	printf("�й� �Է� : ");
	scanf("%d", &num);
	getchar(); // ���๮�ڸ� �����ͼ� ���x. ���� ���� ���� �Է½� �ʿ�
	printf("���� �Է� : ");
	grade = getchar();
	printf("�й� : %d, ���� : %c", num, grade);

	return 0;
}