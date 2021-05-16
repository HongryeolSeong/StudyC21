#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	char str[20];

	// a -> 파일 끝에 추가
	// + -> 데이터 기록 중 언제든지 파일 내용 읽을 수 있게함
	fp = fopen("a.txt", "a+");
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		printf("과일 이름 : ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0) // 경우 1. end 입력시 종료
		{
			break;
		}
		else if (strcmp(str, "list") == 0) // 경우 2. list 입력시 파일 내용 확인
		{
			fseek(fp, 0, SEEK_SET); // 버퍼의 위치 지시자를 맨 첨으로 이동
			while (1)
			{
				fgets(str, sizeof(str), fp); // 파일 내용 읽음
				if (feof(fp)) // 파일 내용 다 읽으면 종료
				{
					break;
				}
				printf("%s", str);
			}
		}
		else // 경우 3. 과일 입력시
		{
			fprintf(fp, "%s\n", str); // 입력한 과일을 파일에 출력
		}
	}
	fclose(fp);

	return 0;
}