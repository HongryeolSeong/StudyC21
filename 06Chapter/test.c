#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int cal, a, b, res;

    while (1) 
    {
        printf("���ϴ� �׸��� �����ϼ���. 1.+ 2.- 3.* 4./ 5.����\n");
        scanf("%d", &cal);

        if (cal == 5) break;

        printf("ù��° ���� �Է��ϼ��� : ");
        scanf("%d", &a);

        printf("�ι�° ���� �Է��ϼ��� : ");
        scanf("%d", &b);
        getchar();

        switch (cal)
        {
        case '1':
            res = a + b;
            printf("%d + %d��(��) %d�Դϴ�.", a, b, res);
            break;
        case '2':
            res = a - b;
            printf("%d - %d��(��) %d�Դϴ�.", a, b, res);
            break;
        case '3':
            res = a * b;
            printf("%d * %d��(��) %d�Դϴ�.", a, b, res);
            break;
        case '4':
            if (b == 0)
            {
                printf("0���� ���� �� �����ϴ�.\n");
                main();
            }
            else
            {
                res = a / b;
                printf("%d / %d��(��) %d�Դϴ�.", a, b, res);
                break;
            }
        default:
            break;
        }
    }
    

    return 0;
}