#include <stdio.h>
#include "student.h" // 사용자 헤더파일

int main()
{
	Student a = { 315, "홍길동" };

	printf("학번 : %d, 이름 : %s\n", a.num, a.name);

	return 0;
}