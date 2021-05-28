#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct      // ����ü ����
{
	int num;
	char name[20];
	double weight;
} Fitness;

void total_number(int count);						// ��ü ��� ȸ�� �� ��ȯ
double average_weight(Fitness** pary, int count);		// ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);			// �ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index);			// ȸ�� ���� ���
void free_ary(Fitness** pary, int count);			// ���� �Ҵ� ���� ����

int main()
{
	int i = 0;
	int count;
	int tnum;
	char tname[80];
	double tw;
	double avg;
	int index;

	Fitness* ary[100];								// ������ �迭 ����

	while (1)
	{
		printf("> ȸ�� ��ȣ : ");
		scanf("%d", &tnum);
		if (tnum < 0) break;
		getchar();

		printf("> �̸� �Է� : ");
		gets(tname);

		printf("> ü�� �Է� : ");
		scanf("%lf", &tw);
		getchar();

		// ���� �Ҵ��� ���� ��� �������� heap���� ����
		ary[i] = (int*)malloc(sizeof(tnum) +(strlen(tname) + 1) + sizeof(tw));
		ary[i]->num = tnum;
		strcpy(ary[i]->name, tname);
		ary[i]->weight = tw;

		i++;
	}
	count = i;

	total_number(count);				// �� ȸ���� ���
	avg = average_weight(ary, count);	// ��� ü�� ���
	index = max_weight(ary, count);		// �ְ� ü���� �ε���
	print_info(ary, index);				// �ְ� ü���� ���� ȸ�� ���
	free_ary(ary, count);				// ���� �Ҵ� ����

	return 0;
}

void total_number(int count)
{
	printf("# �� ȸ�� �� : %d\n", count);
}

double average_weight(Fitness** pary, int count)
{
	int i;
	int res;
	double avg;

	res = 0;

	for (i = 0; i < count; i++)
	{
		res += pary[i]->weight;
	}

	avg = res / (double)count;

	printf("# ��� ü�� : %.1lf\n", avg);

	return avg;
}

int max_weight(Fitness** pary, int count)
{
	int i;
	int maxindex = 0;

	for (i = 1; i < count; i++)
	{
		if (pary[maxindex]->weight < pary[i]->weight)
		{
			maxindex = i;
		}
	}

	return maxindex;
}

void print_info(Fitness** pary, int index)
{
	printf("# ü���� ���� ���ſ� ȸ����?\n");
	printf("> ȸ�� ��ȣ : %d\n", pary[index]->num);
	printf("> �̸� : %s\n", pary[index]->name);
	printf("> ü�� : %.1lf\n", pary[index]->weight);
}

void free_ary(Fitness** pary, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		free(pary[i]);
	}
}