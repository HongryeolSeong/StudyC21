#include <stdio.h>

// 공용체는 멤버끼리 메모리를 공유하므로 임베디드쪽에서 활용.
union student
{
	int num;
	double grade;
};

struct student1
{
	int num;
	double grade;
};

int main()
{
	union student s1 = { 315 }; // 이렇게 하면 공용체는 첫 번째 멤버만 초기화 됨

	printf("학번 : %d\n", s1.num);
	s1.grade = 4.4;
	printf("학점 : %.1lf\n", s1.grade);

	printf("학번 : %d\n", s1.num); // 이렇게 하면 겹쳐져서 이상한 값 나옴

	s1.num = 315; // 다시 대입 후 
	printf("학번 : %d\n", s1.num); // 출력
	
	printf("공용체 크기 : %d\n", sizeof(s1));
	// 공용체는 제일 큰 멤버 변수의 크기만을 할당받아 사용 그리고 멤버 끼리 공유

	struct student1 s2;
	
	printf("구조체 크기 : %d\n", sizeof(s2)); // 12byte + 패딩바이트

	return 0;
}