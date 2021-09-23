## Chapter_9 포인터🎯

변수의 주소 : ex) int a;의 경우 &a는 a의 시작 주소 값   
그 주소를 담는 포인터
* int* pa; pa = &a;의 경우 pa는 a의 시작 주소 값을 담는 포인터(변수)
* *pa는 pa가 가리키는 주소인 a의 데이터 값
* 포인터가 가리키는 자료형과 변수의 데이터타입은 무조건 동일하게 선언
* 포인터의 크기는 주소를 담으므로 항상 4byte   

   
### 포인터 및 포인터가 가리키는 데이터의 상수화   
const int* pa = &a; // 포인터가 가리키는 곳의 데이터를 상수화, pa 간접참조로 a값 못 바꾸게하는 기능   
* //*pa = 30; // 불가   

int* const pb = &b; // 포인터 자체가 상수화   
* //pb = &a; // 불가   

---
_9장 예제   
포인터를 써야하는 이유_   
```C
#include <stdio.h>

void swap(int* pa, int* pb);

int main()
{
	int a = 10, b = 20;

	printf("a:%d, b:%d\n", a, b);
	swap(&a, &b);
	printf("a:%d, b:%d\n", a, b);

	return 0;
}

void swap(int* pa, int* pb)
{
	int temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
```
_위의 코드에서 포인터 사용안할시 a와 b의 값은 바뀌지 않는다._   
