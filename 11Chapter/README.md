## Chapter_11 문자🎯

'a'로 입력된 문자 a는 컴파일을 통해 아스키 코드 값으로 바뀐다   
그러므로 'a' - 65와 같은 연산 가능   
   
띄어쓰기와 엔터도 문자의 일종이므로(아스키 코드 값 가짐)   
입력받을시 화이트 스페이스를 활용해야한다.   
ex) scanf("%c%c", &ch1, &ch2); -> scanf(" %c %c", &ch1, &ch2);   
   
scanf의 경우 모든 자료형을 입력받을 수 있으므로 무거움   
-> 문자만 입출력하는 경우 전용 함수(ch = getchar();, putchar(ch);) 사용시 효율적.   
--> getchar의 경우 getchar();만 사용시 개행문자를 제거하는 기능이 있다   

---
_11장 퀴즈   
대소문자 변환_   
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch1, ch2;
	
	while (1)
	{
		printf("영문자 하나 입력하세요 : ");
		scanf(" %c", &ch1);

		if (ch1 >= 'a' && ch1 <= 'z')
		{
			ch2 = ch1 - 32;
			printf("대문자 변환 결과는 : %c", ch2);
		}
		else if (ch1 >= 'A' && ch1 <= 'Z')
		{
			ch2 = ch1 + 32;
			printf("소문자 변환 결과는 : %c", ch2);
		}
		else
		{
			printf("오류 : 영문자를 입력하세요.\n");
		}
		printf("\n");
	}

	

	return 0;
}
```
![결과7](https://github.com/HongryeolSeong/StudyC21/blob/main/img/%EB%8C%80%EC%86%8C%EB%AC%B8%EC%9E%90.png "대소문자")
