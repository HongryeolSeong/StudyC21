// ��ҹ��� �з�_�迭
#include <stdio.h>
#include <stdlib.h>

void Print_ary(char* pary, int sz);		// �迭 ��� �Լ�
void Sort_ary(char* pary, int sz);		// �迭 ���� �Լ�

int main()
{
	char input_ary[10];					// �Էµ� ���ĺ��� ��� �迭
	char upper_ary[10];					// �Էµ� ���ĺ� �� �빮�ڸ� ��� �迭
	char lower_ary[10];					// �Էµ� ���ĺ� �� �ҹ��ڸ� ��� �迭
	int i;
	int szu = 0;						// upper�迭�� ������
	int szl = 0;						// lower�迭�� ������

	// 1. ���ĺ� �Է�
	gets(input_ary);

	// 2. ��ҹ��� �з�
	for (i = 0; i < strlen(input_ary); i++)
	{
		if (input_ary[i] >= 'A' && input_ary[i] <= 'Z')
		{
			upper_ary[szu] = input_ary[i];
			szu++; // �з��Ͽ� upper�迭�� ������ �� ���� ����
		}
		else if (input_ary[i] >= 'a' && input_ary[i] <= 'z')
		{
			lower_ary[szl] = input_ary[i];
			szl++; // �з��Ͽ� lower�迭�� ������ �� ���� ����
		}
	}

	// 3. ��ҹ��� �迭�� ��� ���� �� ������ ��ҷ� �ι��� ����
	upper_ary[szu] = '\0';
	lower_ary[szl] = '\0';

	// 4. ��ҹ��� �з� ��� ���
	Print_ary(upper_ary, szu);
	printf("\n");
	Print_ary(lower_ary, szl);
	printf("\n");

	// 5. �� �迭�� ���� ����
	Sort_ary(upper_ary, szu);
	Sort_ary(lower_ary, szl);

	// 6. ��� Ȯ��
	Print_ary(upper_ary, szu);
	printf("\n");
	Print_ary(lower_ary, szl);

	return 0;
}

// �迭 ���
void Print_ary(char* pary, int sz)
{
	int i;
	
	for (i = 0; i < sz; i++)
	{
		printf("%c", pary[i]);
	}
}

// �迭 ����
void Sort_ary(char* pary, int sz)
{
	int i, j, temp;

	// ���� ����
	for (i = 1; i < sz; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (pary[j] < pary[j - 1]) // �� ��ҿ� ������ �� ���� ���
			{
				// swap ����
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
}