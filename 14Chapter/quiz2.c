#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[5][4];
	int total1, total2;
	double avg1, avg2;
	int i, j;
	char stu = 'A';

	for (i = 0; i < 5; i++)
	{
		printf("%cÀÇ 4°ú¸ñ Á¡¼ö ÀÔ·Â : ", stu++);
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}

	printf("\n");
	stu = 'A';


	for (i = 0; i < 5; i++)
	{
		total1 = 0;
		for (j = 0; j < 4; j++)
		{
			total1 += score[i][j];
		}
		avg1 = total1 / 4.0;
		printf("%cÀÇ ÃÑ Á¡¼ö : %d, Æò±Õ : %.1lf\n", stu, total1, avg1);
		stu++;

	}

	printf("\n");

	for (j = 0; j < 4; j++)
	{
		total2 = 0;

		for (i = 0; i < 5; i++)
		{
			total2 += score[i][j];
		}

		avg2 = total2 / 5.0;

		printf("%d°ú¸ñ ÃÑ Á¡¼ö : %d, Æò±Õ : %.1lf\n", j + 1, total2, avg2);
	}

	return 0;
}