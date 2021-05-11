#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Login
{
	char* id;
	int pw;
};

int main()
{
	FILE* fl;
	struct Login s1;
	char id[80];
	char temp[80];
	int pw;
	int res;

	printf("아이디와 패스워드를 입력하시오 : ");
	scanf("%s%d", temp, &s1.pw);
	s1.id = (char*)malloc(strlen(temp) + 1); // id 동적할당
	if (s1.id == NULL)
	{
		printf("메모리가 부족합니다.");
		exit(1);
	}
	strcpy(s1.id, temp);

	fl = fopen("password.txt", "r"); // 로그인 정보 담긴 파일 개방
	if (fl == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(fl, "%s%d", id, &pw); // 개방한 파일에서 아이디와 비밀번호 입력받음
		if (res == EOF)
		{
			break;
		}

		if (strcmp(s1.id, id) == 0 && s1.pw == pw) // 사용자가 입력한 값과 파일 내 값을 비교
		{
			printf("로그인되었습니다.");
		}
		else
		{
			printf("ID를 찾을 수 없습니다.");
		}
	}
	
	fclose(fl); // 로그인 파일 닫기

	return 0;
}