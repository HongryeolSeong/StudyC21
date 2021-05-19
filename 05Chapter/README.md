## Chapter_5 선택문🎯

if (조건식) { 실행문; }<br>
else if (조건식) { 실행문; }<br>
else { 실행문; }<br>
<br>
switch (변수)<br>
case 변수의 값:<br>
   실행문;<br>
   break;<br>
default:<br>
   실행문;<br>
   break;<br>

---
_5장 퀴즈<br>
if와 switch를 활용한 계산기_<br>
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Calculator_if
int main()
{
	int a, b, res;
	char cal;

	printf("첫번째 값 입력하세요 : ");
	scanf("%d", &a);

	printf("두번째 값 입력하세요 : ");
	scanf("%d", &b);
	getchar();

	printf("원하는 연산을 입력하세요 : ");
	scanf("%c", &cal);

	if (cal == '+')
	{
		res = a + b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '-')
	{
		res = a - b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '*')
	{
		res = a * b;
		printf("계산 결과는 : %d입니다.", res);
	}
	else if (cal == '/')
	{
		res = a / b;
		printf("계산 결과는 : %d입니다.", res);
	}

	return 0;
}
```
---
_Calculator_switch는 나누기 연산의 경우 제수(divisor)가 0이 되지 않도록 구현하였다._
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Calculator_switch
int main()
{
    int a, b, res;
    char cal;

    printf("첫번째 수를 입력하세요 : ");
    scanf("%d", &a);

    printf("두번째 수를 입력하세요 : ");
    scanf("%d", &b);
    getchar();

    printf("원하는 연산을 입력하세요 : ");
    scanf("%c", &cal);

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

    return 0;
}
```
