#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num, grade;

	//printf("학점 입력 : ");
	//grade = getchar();
	//printf("학번 입력 : ");
	//scanf("%d", &num); // 정수데이터를 찾으므로 자동으로 개행문자는 패스
	////getchar();
	//printf("학번 : %d, 학점 : %c", num, grade);

	
	printf("학번 입력 : ");
	scanf("%d", &num);
	getchar(); // 개행문자를 가져와서 사용x. 정수 다음 문자 입력시 필요
	printf("학점 입력 : ");
	grade = getchar();
	printf("학번 : %d, 학점 : %c", num, grade);

	return 0;
}