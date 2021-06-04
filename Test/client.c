#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct      // ����ü ����
{
	int num;		// ȸ���� ȸ�� ��ȣ
	char name[20];	// ȸ���� �̸�
	double weight;	// ȸ���� ������
} Fitness;

void total_number(int count);						// ��ü ��� ȸ�� �� ���
double average_weight(Fitness** pary, int count);	// ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);			// �ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index);			// ȸ�� ���� ���
void free_ary(Fitness** pary, int count);			// ���� �Ҵ� ���� ����

Fitness* ary[100];			// ������ �迭 ����

int main()
{
	int i;						// �ݺ��� i
	int count = 0;				// �� ȸ�� ��
	int tnum;					// ȸ�� ��ȣ �ӽ� ����
	char tname[80];				// ȸ�� �̸� �ӽ� �迭
	double tw;					// ȸ�� ü�� �ӽ� ����
	double avg;					// ��ü ȸ���� ��� ü��
	int index;					// ȸ�� ������ ��� �迭�� �ε���


	while (1)
	{
		// 1. ȸ�� ��ȣ �Է�
		printf("> ȸ�� ��ȣ : ");
		scanf("%d", &tnum);
		if (count == 0) // �� ó�� ���� �Է½�
		{
			if (tnum < 0) return 0; // ���α׷� ����
		}
		else if (count > 0) // �ι�° �̻���� ���� �Է½�
		{
			if (tnum < 0) break; // �ݺ��� Ż��
		}
		getchar();


		// 2. ȸ�� �̸� �Է�
		printf("> �̸� �Է� : ");
		gets(tname);

		// 3. ȸ�� ü�� �Է�
		printf("> ü�� �Է� : ");
		scanf("%lf", &tw);
		while ((tw < 0) || (tw > 560)) // ��Ȯ�� ������ �Է� ����
		{
			printf("�����Դ� 1~560���� ���ڸ� �Է��ϼ���.\n");
			printf("> ü�� �Է� : ");
			scanf("%lf", &tw);
		}

		// 4. ���� �Ҵ��� ���� ��� �������� heap���� ����
		ary[count] = (Fitness*)malloc(sizeof(Fitness));
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

// ��ü ��� ȸ�� �� ���
void total_number(int count)
{
	printf("# �� ȸ�� �� : %d\n", count);
}

// ��� ü�� ��ȯ
double average_weight(Fitness** pary, int count)
{
	int i;
	int res;
	double avg;

	res = 0;

	for (i = 0; i < count; i++)
	{
		res += pary[i]->weight;	// ȸ���� ������ ����
	}

	avg = res / (double)count;	// res�� ���� ȸ���� ������ ����� ����

	printf("# ��� ü�� : %.1lf\n", avg);

	return avg;
}

// �ִ� ü�� ȸ���� index ��ȯ
int max_weight(Fitness** pary, int count)
{
	int i;
	int maxindex = 0;			// ��ȯ ��ų �ִ� ü�� ȸ���� index

	for (i = 1; i < count; i++)	// 2��° ��Һ��� �� ����
	{
		if (pary[maxindex]->weight < pary[i]->weight)	// �� Ƚ������ �ִ� ü�� ȸ����
		{												// �����Ժ��� ū ȸ���� ���� ���
			maxindex = i;								// �� ȸ���� �ε�����
		}												// maxindex�� ����
	}

	return maxindex;
}

// ȸ�� ���� ���
void print_info(Fitness** pary, int index)
{
	// �ִ� ü�� ȸ���� ���� ���
	printf("# ü���� ���� ���ſ� ȸ����?\n");
	printf("> ȸ�� ��ȣ : %d\n", pary[index]->num);
	printf("> �̸� : %s\n", pary[index]->name);
	printf("> ü�� : %.1lf\n", pary[index]->weight);
}

// ���� �Ҵ� ���� ����
void free_ary(Fitness** pary, int count)
{
	int i;

	for (i = 0; pary[i] != NULL; i++)	// �Ű������� �Ѿ�� ary�� ��Ұ� NULL�ٷ� ������
	{
		free(pary[i]);					// ��Һ��� ���� �Ҵ� ����
	}
}