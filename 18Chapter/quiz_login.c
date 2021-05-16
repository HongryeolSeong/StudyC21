#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Login
{
	char id[80];
	int pw;
};

int main()
{
	FILE* fl;
	struct Login s1;
	char* id;
	char temp[80];
	int pw;
	int res;
	int check = 0;

	while (1)
	{
		printf("아이디를 입력하시오 : ");
		gets(temp);
		id = (char*)malloc(strlen(temp) + 1); // id 동적할당
		if (id == NULL)
		{
			printf("메모리가 부족합니다.");
			exit(1);
		}
		strcpy(id, temp);

		printf("패스워드를 입력하시오 : ");
		scanf("%d", &pw);

		fl = fopen("password.txt", "r"); // 로그인 정보 담긴 파일 개방
		if (fl == NULL)
		{
			printf("파일이 열리지 않았습니다.\n");
			return 1;
		}

		while (1)
		{
			// 개방한 파일에서 아이디와 비밀번호 입력받아 s1의 멤버에 각각 대입
			res = fscanf(fl, "%s%d", s1.id, &s1.pw); 
			if (res == EOF)
			{
				break;
			}

			if (strcmp(s1.id, id) == 0) // 파일의 id와 키보드로 입력받은 id가 같은 경우
			{
				if (s1.pw == pw) // 파일의 pw와 키보드로 입력받은 pw가 같은 경우
				{
					printf("로그인 되었습니다.\n");
					check = 1;
				}
				else // 파일의 pw와 키보드로 입력받은 pw가 다른 경우
				{
					printf("패스워드가 틀립니다.\n");
				}
			}
			else // 파일의 id와 키보드로 입력받은 id가 다른 경우
			{
				printf("아이디가 틀립니다.\n");
				getchar();
			}
		}

		if (check == 1) // 로그인이 된 경우
		{
			break;
		}

		printf("\n");

		fclose(fl); // 로그인 파일 닫기
		free(id);
	}

	return 0;
}