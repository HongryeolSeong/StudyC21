#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	char str[20];

	// a -> ���� ���� �߰�
	// + -> ������ ��� �� �������� ���� ���� ���� �� �ְ���
	fp = fopen("a.txt", "a+");
	if (fp == NULL)
	{
		printf("������ ������ ���߽��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		printf("���� �̸� : ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0) // ��� 1. end �Է½� ����
		{
			break;
		}
		else if (strcmp(str, "list") == 0) // ��� 2. list �Է½� ���� ���� Ȯ��
		{
			fseek(fp, 0, SEEK_SET); // ������ ��ġ �����ڸ� �� ÷���� �̵�
			while (1)
			{
				fgets(str, sizeof(str), fp); // ���� ���� ����
				if (feof(fp)) // ���� ���� �� ������ ����
				{
					break;
				}
				printf("%s", str);
			}
		}
		else // ��� 3. ���� �Է½�
		{
			fprintf(fp, "%s\n", str); // �Է��� ������ ���Ͽ� ���
		}
	}
	fclose(fp);

	return 0;
}