## Chapter_14 다차원 배열과 포인터🎯

1차원 배열 : int str[5];   
2차원 배열 : int str[4][5];   
초기화 시
```C
int num[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
```
3차원 배열
```C
int score[2][3][4] = {
		{ { 72, 80, 95, 60 }, { 68, 98, 83, 90 }, { 75, 72, 84, 90 } }, // 면1
		{ { 66, 85, 90, 80 }, { 95, 92, 88, 95 }, { 43, 72, 56, 75 } } // 면2
	};
```
<br>

2차원 char 배열 : char animal[5][20];   
-> 1차원 char 배열 = 하나의 문자열 이므로, 여러 문자열을 저장하려면 여러 1차원 char 배열이 필요하다.   
-> 한 행에 한 문자열이 저장되는 꼴   
초기화 시
```C
char animal[][10] = { "dog", "tiger", "rabbit", "horse", "cat" };
```
<br>

---
_예제) 5명 학생의 총합과 평균 그리고 4개 과목의 총합과 평균_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[5][4];
	int total1, total2;
	double avg1, avg2;
	int i, j;
	char stu = 'A';

	for (i = 0; i < 5; i++)
	{
		printf("%c의 4과목 점수 입력 : ", stu++);
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}

	printf("\n");
	stu = 'A';


	for (i = 0; i < 5; i++)
	{
		total1 = 0;
		for (j = 0; j < 4; j++)
		{
			total1 += score[i][j];
		}
		avg1 = total1 / 4.0;
		printf("%c의 총 점수 : %d, 평균 : %.1lf\n", stu, total1, avg1);
		stu++;

	}

	printf("\n");

	for (j = 0; j < 4; j++)
	{
		total2 = 0;

		for (i = 0; i < 5; i++)
		{
			total2 += score[i][j];
		}

		avg2 = total2 / 5.0;

		printf("%d과목 총 점수 : %d, 평균 : %.1lf\n", j + 1, total2, avg2);
	}

	return 0;
}
```
![결과8](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EC%B4%9D%ED%95%A9%ED%8F%89%EA%B7%A0.png "총합평균")   
---

포인터 배열 : 포인터 또한 변수이므로 그 포인터를 여러개 가진 배열도 만들 수 있다.   
```C
int main()
{
	char* pary[5];
	int i;

	// 각 포인터 변수에 문자열 상수의 첫 번째 문자 주소 저장
	pary[0] = "dog";
	pary[1] = "elephant";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion";

	for (i = 0; i < 5; i++)
	{
		printf("%s\n", pary[i]);
	}

	return 0;
}
```
2차원으로 활용하고자 할 때
```C
int main()
{
	int ary1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ary2[4] = { 11, 12, 13, 14 };
	int ary3[4] = { 21, 22, 23, 24 };
	int* pary[3] = { ary1, ary2, ary3 };
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%5d", pary[i][j]);
		}
		printf("\n");
	}
	printf("%5d", pary[2][2]);
	return 0;
}
```
![결과9](https://github.com/HongryeolSeong/StudyC21/blob/main/img/res1.png "2차원배열")
<br>

---
_14장 퀴즈   
단어의 회문 테스트_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int flag = 0;
	char str[30];
	int size;
	

	while (1)
	{
		printf("테스트할 단어를 입력하시오. : ");
		scanf("%s", str);
		size = strlen(str);
		printf("배열사이즈는 : %d\n", size);

		char* pa = str;
		char* pb = str + (size - 1);

		for (i = 0; i < size/2; i++)
		{
			if (*pa != *pb)
			{
				flag = -1;
				break;
			}
			else if (*pa == *pb)
			{
				pa++;
				pb--;
			}
			flag = 1;
		}

		if (flag == -1)
		{
			printf("이 단어는 회문이 아닙니다.\n");
		}
		else if (flag == 1)
		{
			printf("이 단어는 회문입니다!!!\n");
		}
	}

	return 0;
}
```
![결과10](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%9A%8C%EB%AC%B8.png "회문")
