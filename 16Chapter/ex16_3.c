#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* pi;
	int* pi_back; // realloc ������ ����� ��� ������
	int size = 5;
	int count = 0;
	int num;
	int i;

	pi = (int*)calloc(size, sizeof(int)); // 5�� ���� �Ҵ� �� �ڵ����� 0���� �ʱ�ȭ
	while (1)
	{
		printf("����� �Է��ϼ��� => ");
		scanf("%d", &num);
		if (num <= 0) break;
		if (count == size) // ���� ���� 5�� ��� ����
		{
			size += 5; // ���� ũ�� �÷���
			pi_back = pi;
			pi = (int*)realloc(pi, size * sizeof(int)); // ���Ҵ�

			if (pi == NULL)
			{
				pi = pi_back;
			}
		}
		pi[count++] = num;
	}
	for (i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi);

	return 0;
}