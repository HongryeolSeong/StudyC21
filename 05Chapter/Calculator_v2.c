#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b, res;
    char cal;

    printf("ù��° ���� �Է��ϼ��� : ");
    scanf("%d", &a);

    printf("�ι�° ���� �Է��ϼ��� : ");
    scanf("%d", &b);
    getchar();

    printf("���ϴ� ������ �Է��ϼ��� : ");
    scanf("%c", &cal);

    switch (cal)
    {
    case '+':
        res = a + b;
        printf("%d %c %d��(��) %d�Դϴ�.", a, cal, b, res);
        break;
    case '-':
        res = a - b;
        printf("%d %c %d��(��) %d�Դϴ�.", a, cal, b, res);
        break;
    case '*':
        res = a * b;
        printf("%d %c %d��(��) %d�Դϴ�.", a, cal, b, res);
        break;
    case '/':
        if (b == 0)
        {
            printf("0���� ���� �� �����ϴ�.\n");
            main();
        }
        else
        {
            res = a / b;
            printf("%d %c %d��(��) %d�Դϴ�.", a, cal, b, res);
            break;
        }
    default:
        break;
    }

    return 0;
}