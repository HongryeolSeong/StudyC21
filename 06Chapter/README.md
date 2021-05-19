## Chapter_6 반복문🎯

while(조건식) { 실행문; }<br>
for ( 초기식; 조건식; 증감식 ) { 실행문; }<br>
do { 실행문; } while (조건식);<br>

---
_6장 퀴즈<br>
구구단_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, i;

	printf("몇 단 구구단을 실행시키겠습니까? : ");
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
		printf("2 ~ 9 사이의 숫자를 입력하세요.\n");
		main();
	}

	return 0;
}
```
![결과1](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EA%B5%AC%EA%B5%AC%EB%8B%A8.png "구구단")
---
_중복for문 활용한 피라미드 모양 출력_
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
![결과2](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%94%BC%EB%9D%BC%EB%AF%B8%EB%93%9C.png "피라미드")
---
_종료기능이 있는 무한반복 계산기_
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
        printf("원하는 연산을 입력하세요(종료는 y) : ");
        scanf(" %c", &cal);

        if (cal == 'y') break;

        printf("첫번째 수를 입력하세요 : ");
        scanf("%d", &a);

        printf("두번째 수를 입력하세요 : ");
        scanf("%d", &b);

        switch (cal)
        {
        case '+':
            res = a + b;
            printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
            break;
        case '-':
            res = a - b;
            printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
            break;
        case '*':
            res = a * b;
            printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
            break;
        case '/':
            if (b == 0)
            {
                printf("0으로 나눌 수 없습니다.\n");
                main();
            }
            else
            {
                res = a / b;
                printf("%d %c %d은(는) %d입니다.", a, cal, b, res);
                break;
            }
        default:
            break;
        }

        printf("\n");

        printf("끝내시겠습니까? ");
        scanf(" %c", &check);

        if (check == 'y')
        {
            break; // while(i)문 탈출
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
![결과3](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EA%B3%84%EC%82%B0%EA%B8%B0.png "계산기")
