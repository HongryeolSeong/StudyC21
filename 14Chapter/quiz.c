#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int flag = 0;
	char str[30];
	int size;
	

	while (1)
	{
		printf("�׽�Ʈ�� �ܾ �Է��Ͻÿ�. : ");
		scanf("%s", str);
		size = strlen(str);
		printf("�迭������� : %d\n", size);

		char* pa = str;
		char* pb = str + (size - 1);

		for (i = 0; i < size/2; i++)
		{
			if (*pa != *pb)
			{
				flag = -1;
				break;
			}
			else if (*pa == *pb)
			{
				pa++;
				pb--;
			}
			flag = 1;
		}

		if (flag == -1)
		{
			printf("�� �ܾ�� ȸ���� �ƴմϴ�.\n");
		}
		else if (flag == 1)
		{
			printf("�� �ܾ�� ȸ���Դϴ�!!!\n");
		}
	}

	return 0;
}