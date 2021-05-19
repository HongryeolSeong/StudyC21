## Chapter_12 문자열🎯

배열과 마찬가지로 문자열은 그 문자열의 첫 문자가 시작하는 주소와 같다.   
   
fgets
* fgets(str, sizeof(str), stdin);
* 입력받는 문자열의 크기를 확인하여 할당된 메모리를 넘어서지 않는지 체크 후 입력.
   
fgetc
* fgetc(stdin);
* 어떤 입력 다음 문자 입력시 개행문자의 방해를 없애기 위해.
* getchar()와 scanf("%c")와 동일
   
fputs
* fputs(str, stdout);
* puts와 달리 자동 개행 함수
   
strcpy, strncpy
* strcpy(str2, str1);, strncpy(str, 복사할 문자열, 원하는 문자 갯수);
   
strcat, strncat
* strcat(str, 붙일 문자열);, strncat(str, 붙일 문자열, 원하는 문자 갯수);
   
strlen
* strlen(str); 문자열의 길이 측정.
   
strcmp, strncmp
* strcmp(str1, str2);, strncmp(str1, str2, 비교할 문자 갯수);
   
---
_12장 퀴즈   
직접 만드는 gets 함수_   
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
