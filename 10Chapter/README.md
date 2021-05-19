## Chapter_10 배열과 포인터🎯

컴파일러는 배열명을 배열의 첫 번째 요소의 주소로 변경한다   
배열명처럼 사용되는 포인터   
* ex) int* pa = ary;이면 pa[2] = pa[1] + pa[0]과 같은 연산이 가능
* pa는 변수라 pa++, pa + i와 같은 연산이 되지만, ary는 상수라 불가   
   
주소 연산시 : 주소 + 정수 => 주소 + (정수 * 해당 주소를 가지는 변수의 크기)   
포인터 연산시 : 포인터 - 포인터 => 값의 차 / 가리키는 자료형의 크기   
   
함수의 입력변수로 배열 사용시, 함수의 매개변수로 포인터를 선언해야함   

---
_10장 퀴즈   
한 배열의 요소를 거꾸로 출력하는 함수_   
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_ary(int* pa, int size);
void swap_ary(int* pa, int size);
void print_ary(int* pa, int size);

int main()
{
	int ary[10];
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	swap_ary(ary, size);
	print_ary(ary, size);

	return 0;
}

void input_ary(int* pa, int size)
{
	int i;

	printf("%d개의 정수값 입력 : ", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", pa + i);
	}
}

void swap_ary(int* pa, int size)
{
	int temp, i;
	int* px = pa;
	int* py = pa + 9;

	for (i = 0; i < 5; i++)
	{
		temp = *(px + i);
		*(px + i) = *(py - i);
		*(py - i) = temp;
	}

}

void print_ary(int* pa, int size)
{
	int i;

	printf("배열 출력\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
}
```
![결과5](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EA%B1%B0%EA%BE%B8%EB%A1%9C.png "거꾸로출력")
---
   
_10장 퀴즈2   
중복된 번호는 입력불가한 로또 배열_
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_lotto(int* pl, int size);
void print_lotto(int* pl, int size);

int main()
{
	int lotto[6];
	int size = sizeof(lotto) / sizeof(lotto[0]);

	input_lotto(lotto, size);
	printf("\n");
	print_lotto(lotto, size);

	return 0;
}

void input_lotto(int* pl, int size)
{
	int flag = 0;
	int i = 0;
	int j;
	int temp;


	while (i < size)
	{
		printf("로또 번호 입력 : ");
		scanf("%d", &temp);
		if (i == 0)
		{
			flag = 1;
		}
		else if (i > 0)
		{
			for (j = 0; j < i; j++)
			{
				if (temp == pl[j])
				{
					printf("중복된 숫자를 입력하지 마시오.\n");
					flag = -1; // 중복된 숫자가 있다는 플래그
					break; // for문을 탈출하여 해당 순서의 번호 입력으로 다시 돌아감
				}
				flag = 1; // 중복된 숫자가 없다는 플래그
			}
		}

		if (flag > 0) // 중복된 숫자 없는경우 로또 배열에 번호 입력
		{
			*(pl + i) = temp;
			i++;
		}
	}
}

void print_lotto(int* pl, int size)
{
	int i;

	printf("로또 번호 출력\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", *(pl + i));
	}
}
```
![결과6](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EB%A1%9C%EB%98%90.png "res6")
