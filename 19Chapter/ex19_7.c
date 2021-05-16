#include <stdio.h>
#pragma pack(push, 1) // #pragma pack(1)�� ����
// ����Ʈ ����θ�Ʈ�� 1�� �ٲ�
// -> ���� ũ�⸦ 1�� ���� -> ����ü ����� ��� ��ġ�� �Ҵ�
// -> ���� ���ǵ� ����ü�� ��� �е�����Ʈ ����x
// -> �������� ũ��� ������� ũ�⸦ ���� �Ͱ� ����
typedef struct
{
	char ch;
	int in;
} Sample1;

// �ٲٱ� ���� ����Ʈ ����θ�Ʈ ��Ģ�� ���� ��
#pragma pack(pop)
typedef struct
{
	char ch;
	int in;
} Sample2;

int main()
{
	printf("Sample1 ����ü�� ũ�� : %d����Ʈ\n", sizeof(Sample1));
	printf("Sample2 ����ü�� ũ�� : %d����Ʈ\n", sizeof(Sample2));

	return 0;
}