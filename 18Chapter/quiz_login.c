#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Login
{
	char id[80];
	int pw;
};

int main()
{
	FILE* fl;
	struct Login s1;
	char* id;
	char temp[80];
	int pw;
	int res;
	int check = 0;

	while (1)
	{
		printf("���̵� �Է��Ͻÿ� : ");
		gets(temp);
		id = (char*)malloc(strlen(temp) + 1); // id �����Ҵ�
		if (id == NULL)
		{
			printf("�޸𸮰� �����մϴ�.");
			exit(1);
		}
		strcpy(id, temp);

		printf("�н����带 �Է��Ͻÿ� : ");
		scanf("%d", &pw);

		fl = fopen("password.txt", "r"); // �α��� ���� ��� ���� ����
		if (fl == NULL)
		{
			printf("������ ������ �ʾҽ��ϴ�.\n");
			return 1;
		}

		while (1)
		{
			// ������ ���Ͽ��� ���̵�� ��й�ȣ �Է¹޾� s1�� ����� ���� ����
			res = fscanf(fl, "%s%d", s1.id, &s1.pw); 
			if (res == EOF)
			{
				break;
			}

			if (strcmp(s1.id, id) == 0) // ������ id�� Ű����� �Է¹��� id�� ���� ���
			{
				if (s1.pw == pw) // ������ pw�� Ű����� �Է¹��� pw�� ���� ���
				{
					printf("�α��� �Ǿ����ϴ�.\n");
					check = 1;
				}
				else // ������ pw�� Ű����� �Է¹��� pw�� �ٸ� ���
				{
					printf("�н����尡 Ʋ���ϴ�.\n");
				}
			}
			else // ������ id�� Ű����� �Է¹��� id�� �ٸ� ���
			{
				printf("���̵� Ʋ���ϴ�.\n");
				getchar();
			}
		}

		if (check == 1) // �α����� �� ���
		{
			break;
		}

		printf("\n");

		fclose(fl); // �α��� ���� �ݱ�
		free(id);
	}

	return 0;
}