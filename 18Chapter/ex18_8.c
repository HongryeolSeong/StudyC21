#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* ifp, * ofp;
	char str[80];
	char* res;

	ifp = fopen("a.txt", "r"); // �Է� �޾ƿ� ������ ������
	if (ifp == NULL)
	{
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");  // ����� ������ ������
	while (1) // NULL ���������� �ݺ�
	{
		//b.txt�� �� ��(str) ���
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL) break;
		str[strlen(str) - 1] = '\0'; // �� ���� ���� ���� ���ڸ� �����ϰ� NULL���� ����
		fputs(str, ofp); // �� �� ���
		fputs(" ", ofp); // �� �� ��� �� �̾ �����̽� ���
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}