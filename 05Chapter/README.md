## Chapter_5 ์ ํ๋ฌธ๐ฏ

if (์กฐ๊ฑด์) { ์คํ๋ฌธ; }<br>
else if (์กฐ๊ฑด์) { ์คํ๋ฌธ; }<br>
else { ์คํ๋ฌธ; }<br>
<br>
switch (๋ณ์)<br>
case ๋ณ์์ ๊ฐ:<br>
   ์คํ๋ฌธ;<br>
   break;<br>
default:<br>
   ์คํ๋ฌธ;<br>
   break;<br>

---
_5์ฅ ํด์ฆ<br>
if์ switch๋ฅผ ํ์ฉํ ๊ณ์ฐ๊ธฐ_<br>
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Calculator_if
int main()
{
	int a, b, res;
	char cal;

	printf("์ฒซ๋ฒ์งธ ๊ฐ ์๋ ฅํ์ธ์ : ");
	scanf("%d", &a);

	printf("๋๋ฒ์งธ ๊ฐ ์๋ ฅํ์ธ์ : ");
	scanf("%d", &b);
	getchar();

	printf("์ํ๋ ์ฐ์ฐ์ ์๋ ฅํ์ธ์ : ");
	scanf("%c", &cal);

	if (cal == '+')
	{
		res = a + b;
		printf("๊ณ์ฐ ๊ฒฐ๊ณผ๋ : %d์๋๋ค.", res);
	}
	else if (cal == '-')
	{
		res = a - b;
		printf("๊ณ์ฐ ๊ฒฐ๊ณผ๋ : %d์๋๋ค.", res);
	}
	else if (cal == '*')
	{
		res = a * b;
		printf("๊ณ์ฐ ๊ฒฐ๊ณผ๋ : %d์๋๋ค.", res);
	}
	else if (cal == '/')
	{
		res = a / b;
		printf("๊ณ์ฐ ๊ฒฐ๊ณผ๋ : %d์๋๋ค.", res);
	}

	return 0;
}
```
---
_Calculator_switch๋ ๋๋๊ธฐ ์ฐ์ฐ์ ๊ฒฝ์ฐ ์ ์(divisor)๊ฐ 0์ด ๋์ง ์๋๋ก ๊ตฌํํ์๋ค._
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Calculator_switch
int main()
{
    int a, b, res;
    char cal;

    printf("์ฒซ๋ฒ์งธ ์๋ฅผ ์๋ ฅํ์ธ์ : ");
    scanf("%d", &a);

    printf("๋๋ฒ์งธ ์๋ฅผ ์๋ ฅํ์ธ์ : ");
    scanf("%d", &b);
    getchar();

    printf("์ํ๋ ์ฐ์ฐ์ ์๋ ฅํ์ธ์ : ");
    scanf("%c", &cal);

    switch (cal)
    {
    case '+':
        res = a + b;
        printf("%d %c %d์(๋) %d์๋๋ค.", a, cal, b, res);
        break;
    case '-':
        res = a - b;
        printf("%d %c %d์(๋) %d์๋๋ค.", a, cal, b, res);
        break;
    case '*':
        res = a * b;
        printf("%d %c %d์(๋) %d์๋๋ค.", a, cal, b, res);
        break;
    case '/':
        if (b == 0)
        {
            printf("0์ผ๋ก ๋๋ ์ ์์ต๋๋ค.\n");
            main();
        }
        else
        {
            res = a / b;
            printf("%d %c %d์(๋) %d์๋๋ค.", a, cal, b, res);
            break;
        }
    default:
        break;
    }

    return 0;
}
```
