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
double average_weight(Fitness** pary, int count);	// ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);			// �ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index);			// ȸ�� ���� ���
void free_ary(Fitness** pary, int count);			// ���� �Ҵ� ���� ����

int main()
{
	int i;
	int count = 0;									// �� ȸ�� ��
	int tnum;										// ȸ�� ��ȣ �ӽ� ����
	int flag = 0;
	char tname[80];									// ȸ�� �̸� �ӽ� �迭
	double tw;										// ȸ�� ü�� �ӽ� ����
	double avg;										// ��ü ȸ���� ��� ü��
	int index;										// ȸ�� ������ ��� �迭�� �ε���

	Fitness* ary[100];								// ������ �迭 ����

	while (1)
	{
		// ȸ�� ��ȣ �Է�
		// TODO : �ݺ��� ��ȣ �Է� �ȵǰ� �� ��
		printf("> ȸ�� ��ȣ : ");
		scanf("%d", &tnum);
		//if (tnum < 0) break;
		if (count == 0) // �� ó�� ���� �Է½�
		{
			if (tnum < 0) return 0; // ���α׷� ����
		}
		else if (count > 0) // �ι�° �̻���� ���� �Է½�
		{
			if (tnum < 0) break; // �ݺ��� Ż��
		}
		getchar();

		// ȸ�� �̸� �Է�
		printf("> �̸� �Է� : ");
		gets(tname);

		// ȸ�� ü�� �Է�
		printf("> ü�� �Է� : ");
		scanf("%lf", &tw);
		while ((tw < 0) || (tw > 560)) // ��Ȯ�� ������ �Է� ����
		{
			printf("�����Դ� 1~560���� ���ڸ� �Է��ϼ���.\n");
			printf("> ü�� �Է� : ");
			scanf("%lf", &tw);
		}

		// ���� �Ҵ��� ���� ��� �������� heap���� ����
		ary[count] = (int*)malloc(sizeof(tnum) +(strlen(tname) + 1) + sizeof(tw));
		ary[count]->num = tnum;
		strcpy(ary[count]->name, tname);
		ary[count]->weight = tw;

		count++;
	}

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