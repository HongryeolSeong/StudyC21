#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Login
{
	char id[80];
	int pw;
};

int main()
{
	FILE* fl;
	struct Login s1;
	char *id;
	char temp[80];
	int pw;
	int res;
	int check = 0;

	while (1)
	{
		printf("���̵�� �н����带 �Է��Ͻÿ� : ");
		scanf("%s%d", temp, &pw);
		id = (char*)malloc(strlen(temp) + 1); // id �����Ҵ�
		if (id == NULL)
		{
			printf("�޸𸮰� �����մϴ�.");
			exit(1);
		}
		strcpy(id, temp);

		fl = fopen("password.txt", "r"); // �α��� ���� ��� ���� ����
		if (fl == NULL)
		{
			printf("������ ������ �ʾҽ��ϴ�.\n");
			return 1;
		}

		while (1)
		{
			res = fscanf(fl, "%s%d", s1.id, &s1.pw); // ������ ���Ͽ��� ���̵�� ��й�ȣ �Է¹���
			if (res == EOF)
			{
				break;
			}

			if (strcmp(s1.id, id) == 0)
			{
				if (s1.pw == pw)
				{
					printf("�α��� �Ǿ����ϴ�.\n");
					check = 1;
				}
				else
				{
					printf("�н����尡 Ʋ���ϴ�.\n");
				}
			}
			else
			{
				printf("���̵� Ʋ���ϴ�.\n");
			}

			//if (strcmp(s1.id, id) == 0 && s1.pw == pw) // ����ڰ� �Է��� ���� ���� �� ���� ��
			//{
			//	printf("�α��εǾ����ϴ�.");
			//	check = 1;
			//}
			//else
			//{
			//	printf("ID�� ã�� �� �����ϴ�.");
			//}
		}

		if (check == 1)
		{
			break;
		}

		printf("\n");

		fclose(fl); // �α��� ���� �ݱ�
	}

	return 0;
}