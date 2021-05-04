#include <stdio.h>
#include <string.h>

int main()
{
	char str1[80] = "pear";
	char str2[80] = "peach";

	if (strcmp(str1, str2) > 0) // >:1 <:-1 =:0
	{
		printf("%s\n", str1);
	}
	else
	{
		printf("%s\n", str2);
	}

	printf("앞에서 3개의 문자만 비교하면?\n");
	if (strncmp(str1, str2, 3) == 0)
	{
		printf("같다.\n");
	}
	else
	{
		printf("다르다.\n");
	}
	return 0;
}