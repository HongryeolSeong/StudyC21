#include <stdio.h>

char* my_strcpy(char* ps1, char* ps2);

int main()
{
	char str[80] = "strawberry";

	printf("�ٲ���� ���ڿ� : %s\n", str);
	my_strcpy(str, "apple");
	printf("�ٲ� �� ���ڿ� : %s\n", str);
	printf("�ٸ� ���ڿ� ���� : %s\n", my_strcpy(str, "kiwi"));

	return 0;
}

char* my_strcpy(char* ps1, char* ps2)
{
	char* po = ps1;
	while (*ps2 != '\0')
	{
		*ps1 = *ps2;
		ps1++;
		ps2++;
	}
	*ps1 = '\0';

	return po;
}