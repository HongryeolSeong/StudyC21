#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Login
{
	char* id;
	int pw;
};

int main()
{
	FILE* fl;
	struct Login s1;
	char id[80];
	char temp[80];
	int pw;
	int res;

	printf("���̵�� �н����带 �Է��Ͻÿ� : ");
	scanf("%s%d", temp, &s1.pw);
	s1.id = (char*)malloc(strlen(temp) + 1); // id �����Ҵ�
	if (s1.id == NULL)
	{
		printf("�޸𸮰� �����մϴ�.");
		exit(1);
	}
	strcpy(s1.id, temp);

	fl = fopen("password.txt", "r"); // �α��� ���� ��� ���� ����
	if (fl == NULL)
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(fl, "%s%d", id, &pw); // ������ ���Ͽ��� ���̵�� ��й�ȣ �Է¹���
		if (res == EOF)
		{
			break;
		}

		if (strcmp(s1.id, id) == 0 && s1.pw == pw) // ����ڰ� �Է��� ���� ���� �� ���� ��
		{
			printf("�α��εǾ����ϴ�.");
		}
		else
		{
			printf("ID�� ã�� �� �����ϴ�.");
		}
	}
	
	fclose(fl); // �α��� ���� �ݱ�

	return 0;
}