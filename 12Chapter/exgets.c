#include <stdio.h>

void my_gets(char* ps);

int main()
{
	int i = 0;
	char str[20];
	char ch;

	/*do
	{
		ch = getchar();
		str[i] = ch;
		i++;
	} while (ch != '\n');

	str[i] = '\0';*/

	my_gets(str);

	printf("%s", str);

	return 0;
}

void my_gets(char* ps)
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		*ps = ch;
		ps++;
	}
	*ps = '\0';
}