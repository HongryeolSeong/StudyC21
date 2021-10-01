## Chapter_17 사용자 정의 자료형🎯

* 구조체 : int, char, 배열 등 여러 자료형을 묶어서 사용 가능한 복합 자료형   
```C
#include <stdio.h>

struct student // 메모리 할당x
{
	int num;
	double grade;
}; // ; 필수

int main()
{
	struct student s1; // 구조체 변수 생성 동시에 메모리 할당 됨

	s1.num = 2;
	s1.grade = 2.7;
}
```
<br>

* 다른 구조체를 멤버로 갖는 구조체 사용시   
```c
struct profile
{
	int age;
	double height;
};

struct student
{
	struct profile pf;
};

int main()
{
	struct student yuni;

	yuni.pf.age = 17;
	yuni.pf.height = 164.5;
}
```
<br>

* 구조체 변수의 초기화와 대입 연산   
```C
struct student
{
	int id;
	char name[20];
	double grade;
};

int main()
{
	struct student s1 = { 315, "홍길동", 2.4 }, // 구조체 변수의 초기화
		       s2 = { 316, "이순신", 3.7 },
		       s3 = { 317, "세종대왕", 4.4 };

	struct student max; // 대입 시킬 구조체 변수

	max = s1; // 한 구조체 변수에 다른 구조체 변수를 대입
	if (s2.grade > max.grade) max = s2;
	if (s3.grade > max.grade) max = s3;
}
```
<br>

* 구조체를 매개변수로 하는 함수
```C
struct vision
{
	double left;
	double right;
};

struct vision exchange(struct vision robot);

int main()
{
	struct vision robot;

	scanf("%lf%lf", &(robot.left), &(robot.right));
	robot = exchange(robot);
}

struct vision exchange(struct vision robot) { 교체 실행문; }
```
<br>

* 구조체 포인터
```C
struct score
{
	int kor;
	int eng;
	int math;
};

int main()
{
	struct score yuni = { 90, 80 };
	struct score* ps = &yuni; // 구조체 변수 yuni의 주소를 담는 포인터 ps.

	printf("국어 : %d\n", (*ps).kor); // *의 참조 연산이 우선 순위이므로 괄호 필수
	printf("영어 : %d\n", ps->eng); // 위와 동일한 결과 출력
}
```
<br>

* 구조체 배열
```C
int main()
{
	struct address list[5] = {
		{"홍길동", 23, "111-1111", "울릉도 독도"}, // address 구조체의 변수인 list배열의 초기화
		{"이순신", 35, "222-2222", "서울 건천동"},
		{"장보고", 19, "333-3333", "완도 청해진"},
		{"유관순", 15, "444-4444", "충남 천안"},
		{"안중근", 45, "555-5555", "황해도 해주"}
	};

	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n",
			list[i].name, list[i].age, list[i].tel, list[i].addr);
	}
}
```
위의 구조체를 매개변수로 넘긴 출력 함수 활용시
```C
void print_list(struct address* lp) // 구조체 변수인 list[5]를 포인터로 넘겨 받음
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n",
			(*(lp + i)).name, (*(lp + i)).age, (*(lp + i)).tel, (*(lp + i)).addr);
			//(lp + i)->name, (lp + i)->age, (lp + i)->tel, (lp + i)->addr); // 위와 동일한 결과 출력
	}
}
```
<br>

* 자기 참조 구조체   
자신의 구조체를 가르키는 포인터 선언을 통해 여러 구조체 변수가 연결된 형태 구현 가능
```C
struct list
{
	int num;
	struct list* next; // 구조체 자신을 가리키는 포인터 next
};

int main()
{
	struct list a = { 10, 0 }, b = { 20, 0 }, c = { 30, 0 };
	struct list* head = &a, * current;
	// 구조체 a를 가르키는 head와 list구조체를 가르키는 current 포인터

	a.next = &b; // next포인터로 구조체들을 연결
	b.next = &c;

	printf("head->num : %d\n", head->num);
	printf("head->next->num : %d\n", head->next->num);

	printf("list all : ");
	current = head;
	while (current != NULL) // 연결 리스트 구조
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

	return 0;
}
```
<br>

* 공용체   
구조체와 비슷하지만 모든 멤버가 하나의 저장 공간을 같이 사용   
효율적 메모리 활용이 중요한 임베디드에서 많이 활용   
```C
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

	s1.num = 315; // 그러므로 다시 대입 후 
	printf("학번 : %d\n", s1.num); // 출력해야함
	
	printf("공용체 크기 : %d\n", sizeof(s1));
	// 공용체는 제일 큰 멤버 변수의 크기만을 할당받아 사용 그리고 멤버 끼리 공유

	struct student1 s2;
	
	printf("구조체 크기 : %d\n", sizeof(s2)); // 12byte + 패딩바이트
}
```
<br>

* 열거형   
역시 구조체와 비슷하지만 멤버들이 정수로 정의됨.   
```C
enum season { SPRING, SUMMER, FALL, WINTER };

int main()
{
	enum season ss;
	char* pc = NULL;

	scanf("%d", &ss); // 정수값 입력

	switch (ss)
	{
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "swimming";
		break;
	case FALL:
		pc = "trip";
		break;
	case WINTER:
		pc = "skiing";
		break;
	}

	printf("나의 레저 활동 => %s\n", pc);
	printf("%d %d %d %d\n", SPRING, SUMMER, FALL, WINTER);
	// enum의 멤버는 정수값을 가진다. 이웃 멤버와 +1 관계 가짐
	// if FALL = 100 이면 SUMMER = 1, WINTER = 101 이 된다.

	return 0;
}
```
<br>

* typedef   
구조체, 공용체, 열거형의 변수 생성시 예약어를 생략하게 해주는 형 재정의   
```C
typedef struct {
	int num;
	double grade;
}Student;

void print_data(Student* ps);

int main()
{
	Student s1 = { 315, 4.2 };

	print_data(&s1);

	return 0;
}

void print_data(Student* ps)
{
	printf("학번 : %d\n", ps->num);
	printf("학점 : %.1lf\n", ps->grade);
}
```
   
---
_17장 퀴즈   
5명 사원의 아이디, 이름, 급여 입력 후 총/평균 급여 구하기_
```C
typedef struct employee {
	int id;
	char* name;
	int salary;
}Employee; // struct employee를 Employee로 재정의

int main()
{
	char temp[80];
	int i, total;
	double avg;
	Employee list[5];

	for (i = 0; i < 5; i++)
	{
		printf("%d번째 인원의 아이디, 이름, 급여를 입력하시오. : ", i + 1);
		scanf("%d%s%d", &list[i].id, temp, &list[i].salary);

		// 구조체 멤버인 name을 동적 할당하는 과정
		list[i].name = (char*)malloc(strlen(temp) + 1);
		if (list[i].name == NULL)
		{
			printf("메모리가 부족합니다.");
			exit(1);
		}
		strcpy(list[i].name, temp); //if (list[i].name != NULL) 사용 해도 됨
	}

	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("아이디 : %d, 이름 : %s, 급여 : %d\n", list[i].id, list[i].name, list[i].salary);
	}

	printf("\n");

	total = 0;
	for (i = 0; i < 5; i++)
	{
		total += list[i].salary;
	}
	avg = total / 5.0;
	printf("급여 총액 : %d, 평균 급여 : %.1lf", total, avg);

	printf("\n");

	for (i = 0; i < 5; i++) // 동적 할당된 메모리 반환
	{
		free(list[i].name);
	}
}
```
