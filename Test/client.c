#include <stdio.h>

typedef struct      // ����ü ����
{
	int num;
	char name[20];
	int weight;
} Fitness;

Fitness* ary[100];									// ������ �迭 ����
void total_number(int count);						// ��ü ��� ȸ�� �� ��ȯ
int average_weight(Fitness** pary, int count);	// ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);			// �ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index);			// ȸ�� ���� ���
void free_ary(Fitness** pary, int count);			// ���� �Ҵ� ���� ����

int main()
{
	int i = 0;
	int count;
	int avg;
	Fitness list[100];

	while (1)
	{
		printf("> ȸ�� ��ȣ : ");
		scanf("%d", &list[i].num);
		if (list[i].num < 0) break;
		getchar();

		printf("> �̸� �Է� : ");
		gets(list[i].name);

		printf("> ü�� �Է� : ");
		scanf("%d", &list[i].weight);
		getchar();


		i++;
	}
	count = i;

	total_number(count);
	avg = average_weight(list, count);

	return 0;
}

void total_number(int count)
{
	printf("# �� ȸ�� �� : %d", count);
}

int average_weight(Fitness** pary, int count)
{
	int i;
	int res;
	int avg;

	res = 0;

	for (i = 0; i < count; i++)
	{
		res += pary[i]->weight;
	}

	avg = res / count;

	printf("# ��� ü�� : %.1lf", avg);

	return avg;
}

int max_weight(Fitness** pary, int count)
{
	int i, j;
	printf("ü���� ���� ���ſ� ȸ����?\n");
	for (i = 0; i < count; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (pary[j]->weight > pary[i]->weight) break;
		}
	}
}

void print_info(Fitness** pary, int index)
{

}

void free_ary(Fitness** pary, int count)
{

}