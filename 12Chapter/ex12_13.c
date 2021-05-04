#include <stdio.h>

char* my_strcpy(char* ps1, char* ps2);

int main()
{
	char str[80] = "strawberry";

	printf("바뀌기전 문자열 : %s\n", str);
	my_strcpy(str, "apple");
	printf("바뀐 후 문자열 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi"));

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