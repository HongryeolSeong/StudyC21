#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b, res;
    int i = 1;
    char cal, check;

	while (i)
	{
        printf("���ϴ� ������ �Է��ϼ���(����� y) : ");
        scanf(" %c", &cal);

        if (cal == 'y') break;

        printf("ù��° ���� �Է��ϼ��� : ");
        scanf("%d", &a);

        printf("�ι�° ���� �Է��ϼ��� : ");
        scanf("%d", &b);
        getchar();


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

        printf("\n");

        printf("������?");
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