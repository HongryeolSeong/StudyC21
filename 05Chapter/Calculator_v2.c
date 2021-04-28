#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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