## Chapter_6 ๋ฐ๋ณต๋ฌธ๐ฏ

while(์กฐ๊ฑด์) { ์คํ๋ฌธ; }<br>
for ( ์ด๊ธฐ์; ์กฐ๊ฑด์; ์ฆ๊ฐ์ ) { ์คํ๋ฌธ; }<br>
do { ์คํ๋ฌธ; } while (์กฐ๊ฑด์);<br>

---
_6์ฅ ํด์ฆ<br>
๊ตฌ๊ตฌ๋จ_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, i;

	printf("๋ช ๋จ ๊ตฌ๊ตฌ๋จ์ ์คํ์ํค๊ฒ ์ต๋๊น? : ");
	scanf("%d", &a);

	if (a > 1 && a < 10)
	{
		for (i = 1; i < 10; i++)
		{
			printf("%d * %d = %d\n", a, i, a * i);
		}
	}
	else
	{
		printf("2 ~ 9 ์ฌ์ด์ ์ซ์๋ฅผ ์๋ ฅํ์ธ์.\n");
		main();
	}

	return 0;
}
```
![๊ฒฐ๊ณผ1](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EA%B5%AC%EA%B5%AC%EB%8B%A8.png "๊ตฌ๊ตฌ๋จ")
---
_์ค๋ณตfor๋ฌธ ํ์ฉํ ํผ๋ผ๋ฏธ๋ ๋ชจ์ ์ถ๋ ฅ_
```C
#include <stdio.h>

int main()
{
	int i, j, k;

	for (i = 1; i < 10; i++)
	{
		for (j = 0; j < 10 - i; j++)
		{
			printf(" ");
		}
		for (k = 0; k < 2*i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
```
![๊ฒฐ๊ณผ2](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%94%BC%EB%9D%BC%EB%AF%B8%EB%93%9C.png "ํผ๋ผ๋ฏธ๋")
---
_์ข๋ฃ๊ธฐ๋ฅ์ด ์๋ ๋ฌดํ๋ฐ๋ณต ๊ณ์ฐ๊ธฐ_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b, res;
    int i = 1;
    char cal, check;

	while (i)
	{
        printf("์ํ๋ ์ฐ์ฐ์ ์๋ ฅํ์ธ์(์ข๋ฃ๋ y) : ");
        scanf(" %c", &cal);

        if (cal == 'y') break;

        printf("์ฒซ๋ฒ์งธ ์๋ฅผ ์๋ ฅํ์ธ์ : ");
        scanf("%d", &a);

        printf("๋๋ฒ์งธ ์๋ฅผ ์๋ ฅํ์ธ์ : ");
        scanf("%d", &b);

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

        printf("\n");

        printf("๋๋ด์๊ฒ ์ต๋๊น? ");
        scanf(" %c", &check);

        if (check == 'y')
        {
            break; // while(i)๋ฌธ ํ์ถ
        }
        else
        {
            i = 1;
        }

        printf("\n");
	}

	return 0;
}
```
![๊ฒฐ๊ณผ3](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EA%B3%84%EC%82%B0%EA%B8%B0.png "๊ณ์ฐ๊ธฐ")
