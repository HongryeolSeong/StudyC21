#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void calc();

int main()
{
    calc();

    return 0;
}

void calc()
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
        getchar();


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

        valid();
    }
}

int valid()
{
    int i = 0;
    char check = "";

    printf("끝내시겠습니까?");
    scanf(" %c", &check);

    if (check == 'y')
    {
        exit(1);
    }
    else if (check == 'n')
    {
        i = 1;
    }
    else
    {
        printf("y 또는 n을 입력하세요.\n");
        valid();
    }

    return i;
}