## Chapter_16 메모리 동적 할당🎯

선언을 통해 저장 공간을 미리 확보할 수 있지만, 때로는 프로그램 실행 중에 저장 공간을 할당할 수 있어야 한다.   

* malloc과 free 함수   
stdlib.h 헤더 인클루드 후 사용 가능   
```C
int main()
{
	int* pi; // 동적 할당 영역을 연결할 포인터 pi

	pi = (int *)malloc(sizeof(int)); // 동적 메모리 할당
	if (pi == NULL) // 동적 할당 실패시 = 포인터가 NULL 반환시
	{
		printf("# 메모리가 부족합니다.\n");
		exit(1); // 프로그램 종료
	}

	*pi = 10;
	
	free(pi); // 동적 메모리 반환
}
```
위처럼 malloc()으로 영역을 동적 할당 후 free()로 해당 영역을 반환해야한다   
<br>

* 동적 할당 영역을 배열로 활용   
할당된 공간의 시작위치를 포인터로 연결시 해당 공간을 배열로 사용 가능.   
```C
int main()
{
	int* pi;
	int i, sum = 0; // sum은 연산시 처음 값이 쓰레기 값이면 안되므로 0으로 초기화
	pi = (int*)malloc(5 * sizeof(int));
	if (pi == NULL)
	{
		printf("메모리가 부족합니다!\n");
		exit(1);
	}
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &pi[i]); // 메모리를 배열처럼 사용
		sum += pi[i];
	}
	free(pi);
}
```
<br>

* calloc, realloc 함수   
calloc() : 메모리 할당시 공간을 0으로 초기화   
realloc() : 이미 동적 할당된 공간의 크기를 조절   
realloc() 유의점   
-> 공간 부족시 새 메모리 공간 할당하여 기존 요소 복사   
-> but null이 반환될 시 기존 주소 잃어버림   
--> 임시 포인터에 realloc 공간 반환 후 사용할 것   
```C
int main()
{
	int* pi; // 동적 할당 공간과 연결할 포인터
	int* pi_back; // realloc 오류를 대비한 백업 포인터

	pi = (int*)calloc(size, sizeof(int)); // 5개 공간 할당 후 자동으로 0으로 초기화
	while (1)
	{
		if (count == size) // 저장 공간 모두 사용시
		{
			size += 5; // 공간 크기 늘려서
			pi_back = pi; // 할당 실패 방지 pi의 공간 주소를 pi_back으로 백업
			pi = (int*)realloc(pi, size * sizeof(int)); // 재할당
			if (pi == NULL) // 공간 할당 실패시
			{
				pi = pi_back; // 백업했던 공간의 주소를 다시 기존 pi포인터와 연결
			}
		}
	}
	
	for (i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi);
}
```
위처럼 pi의 백업 포인터인 pi_back을 활용하여 realloc의 할당 실패를 방지하였다.   
<br>

* 동적 할당 활용한 문자열 처리   
동적 할당을 통해 효율적인 문자열 저장 공간 관리   
```C
int main()
{
	char temp[80]; // 임시 문자열 배열
	char* str[3]; // 최종 문자열 배열
	int i;

	for (i = 0; i < 3; i++)
	{
		gets(temp);
		str[i] = (char*)malloc(strlen(temp) + 1); // 임시 배열 길이에 + 1 하여 널문자까지 입력되게 함
		strcpy(str[i], temp); // 동적 할당 된 임시 배열을 최종 배열인 str에 복사
	}

	for (i = 0; i < 3; i++) // 동적 할당된 문자열 배열의 공간을 해제
	{
		free(str[i]);
		printf("할당된 메모리가 반환되었습니다.\n");
	}
}
```
