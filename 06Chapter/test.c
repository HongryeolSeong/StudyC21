#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int cal, a, b, res;

    while (1) 
    {
        printf("원하는 항목을 선택하세요. 1.+ 2.- 3.* 4./ 5.종료\n");
        scanf("%d", &cal);

        if (cal == 5) break;

        printf("첫번째 수를 입력하세요 : ");
        scanf("%d", &a);

        printf("두번째 수를 입력하세요 : ");
        scanf("%d", &b);
        getchar();

        switch (cal)
        {
        case '1':
            res = a + b;
            printf("%d + %d은(는) %d입니다.", a, b, res);
            break;
        case '2':
            res = a - b;
            printf("%d - %d은(는) %d입니다.", a, b, res);
            break;
        case '3':
            res = a * b;
            printf("%d * %d은(는) %d입니다.", a, b, res);
            break;
        case '4':
            if (b == 0)
            {
                printf("0으로 나눌 수 없습니다.\n");
                main();
            }
            else
            {
                res = a / b;
                printf("%d / %d은(는) %d입니다.", a, b, res);
                break;
            }
        default:
            break;
        }
    }
    

    return 0;
}