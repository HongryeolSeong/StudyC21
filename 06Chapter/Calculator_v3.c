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

        printf("끝낼래?");
        scanf(" %c", &check);

        if (check == 'y')
        {
            break;
        }
        else
        {
            i = 1;
        }

	}

	return 0;
}