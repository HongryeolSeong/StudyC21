## Chapter_7 ν¨μπ―

ν¨μ μμ± μ’λ₯<br>
1. λ©μΈ ν¨μμ μμ±   
2. μμΆλ ₯μ΄ μλ ν¨μ μμ± : void func() { μ€νλ¬Έ; }   
3. μλ ₯μ΄ μλ ν¨μ μμ± : void func( λ§€κ°λ³μ1 μ μΈ, λ§€κ°λ³μ2 μ μΈ ) { μ€νλ¬Έ; }   
4. μμΆλ ₯μ΄ μλ ν¨μ μμ± : λ°ννμ func( λ§€κ°λ³μ1 μ μΈ, λ§€κ°λ³μ2 μ μΈ ) { μ€νλ¬Έ; return λ°νν  λ³μ; }   

---
_7μ₯ ν΄μ¦   
μ¬λ¬ ν¨μλ₯Ό νμ©ν κ³μ°κΈ°_   
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum();
int minus();
int multi();
int divi();
int value1();
int value2();

int main()
{
	int res;
	char cal;

	while (1)
	{
		printf("μνλ λ©λ΄ μ ννμΈμ.");
		scanf(" %c", &cal);

		switch (cal)
		{
		case '+':
			res = sum();
			printf("κ²°κ³Όλ : %d", res);
			break;
		case '-':
			res = minus();
			printf("κ²°κ³Όλ : %d", res);
			break;
		case '*':
			res = multi();
			printf("κ²°κ³Όλ : %d", res);
			break;
		case '/':
			res = divi();
			printf("κ²°κ³Όλ : %d", res);
			break;
		case 'q':
			exit(1);
		default:
			break;
		}

		printf("\n");
		printf("\n");
	}

	return 0;
}

int sum()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a + b;

	return res;
}

int minus()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a - b;

	return res;
}

int multi()
{
	int a, b, res;

	a = value1();
	b = value2();

	res = a * b;

	return res;
}

int divi()
{
	int a, b;
	int res = 0;

	a = value1();
	b = value2();

	if (b == 0)
	{
		printf("λλλ μλ 0μ΄ λλ©΄ μλ©λλ€.\n");
	}
	else
	{
		res = a / b;
	}

	return res;
}

int value1()
{
	int a;

	printf("μ²« λ²μ§Έ μ«μλ₯Ό μλ ₯νμΈμ : ");
	scanf("%d", &a);
		
	return a;
}

int value2()
{
	int b;
	
	printf("λ λ²μ§Έ μ«μλ₯Ό μλ ₯νμΈμ : ");
	scanf("%d", &b);

	return b;
}
```
![κ²°κ³Ό4](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%ED%95%A8%EC%88%98%EA%B3%84%EC%82%B0%EA%B8%B0.png "ν¨μκ³μ°κΈ°")
