#include <stdio.h>

// ����ü�� ������� �޸𸮸� �����ϹǷ� �Ӻ�����ʿ��� Ȱ��.
union student
{
	int num;
	double grade;
};

struct student1
{
	int num;
	double grade;
};

int main()
{
	union student s1 = { 315 }; // �̷��� �ϸ� ����ü�� ù ��° ����� �ʱ�ȭ ��

	printf("�й� : %d\n", s1.num);
	s1.grade = 4.4;
	printf("���� : %.1lf\n", s1.grade);

	printf("�й� : %d\n", s1.num); // �̷��� �ϸ� �������� �̻��� �� ����

	s1.num = 315; // �ٽ� ���� �� 
	printf("�й� : %d\n", s1.num); // ���
	
	printf("����ü ũ�� : %d\n", sizeof(s1));
	// ����ü�� ���� ū ��� ������ ũ�⸸�� �Ҵ�޾� ��� �׸��� ��� ���� ����

	struct student1 s2;
	
	printf("����ü ũ�� : %d\n", sizeof(s2)); // 12byte + �е�����Ʈ

	return 0;
}