#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	int age;
	char name[20];

	fp = fopen("a.txt", "r");

	fscanf(fp, "%d", &age);
	while (fgetc(fp) != '\n') {} // ���� ������ �ذ�
	//fgets(name, sizeof(name), fp); // 17"\n"���� ���� ���ڰ� �ٷ� �Է� �Ź���
	fscanf(fp, "%s", name);

	printf("���� : %d, �̸� : %s", age, name);
	fclose(fp);

	return 0;
}