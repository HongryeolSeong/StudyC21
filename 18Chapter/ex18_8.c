#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* ifp, * ofp;
	char str[80];
	char* res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	/*if (ofp == NULL) // 주석해도 오류 없음
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}*/

	while (1)
	{
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL)
		{
			break;
		}
		str[strlen(str) - 1] = '\0';
		fputs(str, ofp);
		fputs(" ", ofp);
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}