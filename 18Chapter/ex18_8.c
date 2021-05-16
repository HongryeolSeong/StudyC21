#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* ifp, * ofp;
	char str[80];
	char* res;

	ifp = fopen("a.txt", "r"); // 입력 받아올 파일의 포인터
	if (ifp == NULL)
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");  // 출력할 파일의 포인터
	while (1) // NULL 만날때까지 반복
	{
		//b.txt에 한 줄(str) 출력
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL) break;
		str[strlen(str) - 1] = '\0'; // 한 줄의 끝에 개행 문자를 제거하고 NULL문자 삽입
		fputs(str, ofp); // 한 줄 출력
		fputs(" ", ofp); // 한 줄 출력 후 이어서 스페이스 출력
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}