## Chapter_12 ๋ฌธ์์ด๐ฏ

๋ฐฐ์ด๊ณผ ๋ง์ฐฌ๊ฐ์ง๋ก ๋ฌธ์์ด์ ๊ทธ ๋ฌธ์์ด์ ์ฒซ ๋ฌธ์๊ฐ ์์ํ๋ ์ฃผ์์ ๊ฐ๋ค.   
   
fgets
* fgets(str, sizeof(str), stdin);
* ์๋ ฅ๋ฐ๋ ๋ฌธ์์ด์ ํฌ๊ธฐ๋ฅผ ํ์ธํ์ฌ ํ ๋น๋ ๋ฉ๋ชจ๋ฆฌ๋ฅผ ๋์ด์์ง ์๋์ง ์ฒดํฌ ํ ์๋ ฅ.
   
fgetc
* fgetc(stdin);
* ์ด๋ค ์๋ ฅ ๋ค์ ๋ฌธ์ ์๋ ฅ์ ๊ฐํ๋ฌธ์์ ๋ฐฉํด๋ฅผ ์์ ๊ธฐ ์ํด.
* getchar()์ scanf("%c")์ ๋์ผ
   
fputs
* fputs(str, stdout);
* puts์ ๋ฌ๋ฆฌ ์๋ ๊ฐํ ํจ์
   
strcpy, strncpy
* strcpy(str2, str1);, strncpy(str, ๋ณต์ฌํ  ๋ฌธ์์ด, ์ํ๋ ๋ฌธ์ ๊ฐฏ์);
   
strcat, strncat
* strcat(str, ๋ถ์ผ ๋ฌธ์์ด);, strncat(str, ๋ถ์ผ ๋ฌธ์์ด, ์ํ๋ ๋ฌธ์ ๊ฐฏ์);
   
strlen
* strlen(str); ๋ฌธ์์ด์ ๊ธธ์ด ์ธก์ .
   
strcmp, strncmp
* strcmp(str1, str2);, strncmp(str1, str2, ๋น๊ตํ  ๋ฌธ์ ๊ฐฏ์);
   
---
_12์ฅ ํด์ฆ   
์ง์  ๋ง๋๋ gets ํจ์_   
```C
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
```
