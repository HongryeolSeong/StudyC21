## Chapter_18 파일 입출력🎯

C의 다양한 파일 입출력 함수를 활용하여 일회성 데이터가 아닌 데이터 다루기   
   
* 파일 개방 및 폐쇄
파일에 데이터 입/출력하기 전 준비 단계.   
fopen과 fclose 함수를 이용함.   
[개방 모드 정리](https://bite-sized-learning.tistory.com/318 "모드참고")
```C
int main()
{
	FILE* fp; // 파일 구조체를 가리키는 포인터

	// 파일 개방
	// fopen()이 파일은 찾는 기본 위치는 "현재 작업 디렉터리"
	fp = fopen("a.txt", "r"); // 파일 정보가 담긴 스트림 파일의 버퍼의 주소를 담는 fp
	if (fp == NULL) // 파일이 없는 경우 = 주소가 NULL
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1; // 프로그램 종료
	}
	printf("파일이 열렸습니다.\n");

	// 파일 폐쇄
	fclose(fp);
}
```   
fopen()과는 다르게 fclose()는 오류 발생시 EOF(= -1)을 반환한다.

<br>

* 스트림 파일과 FILE 구조체   
스트림 파일은 프로그램과 입출력 장치 사이의 다리 역할   
1. 스트림 파일은 메모리에 버퍼와 FILE 구조체를 둔다
2. 버퍼의 상태를 파악하여 FILE 구조체 변수에 저장한다
3. 프로그램에 FILE 변수의 주소를 반환하여 파일의 정보를 읽거나 입출력이 되게 한다   
<br>

* fgetc
파일 개방 후 파일 내 데이터 읽어오기   
![결과11](https://github.com/HongryeolSeong/StudyC21/blob/main/img/fileres1.png "fileres1")
```C
int main()
{
	FILE* fp;
	int ch;

	fp = fopen("a.txt", "r"); // 읽기 개방 모드
	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp); // 파일에서 문자 하나씩 읽어오기
		if (ch == EOF) // 더 이상 읽을 문자가 없는 경우
		{
			break;
		}
		putchar(ch); // 버퍼에 저장된 문자를 화면에 출력
	}
	fclose(fp);
}
```   
![결과12](https://github.com/HongryeolSeong/StudyC21/blob/main/img/fileres2.png "fileres2")
<br>
<br>

* fputc   
파일 개방 후 파일에 데이터 출력하기   
```C
int main()
{
	FILE* fp;
	char str[] = "banana";
	int i;

	// 파일 개방 - 쓰기 모드
	fp = fopen("b.txt", "w"); // b.txt가 없는 경우 새로 만듦
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	// 파일에 str 출력
	i = 0;
	while (str[i] != '\0') // 널문자를 만날때 까지
	{
		fputc(str[i], fp); // b.txt에 str을 출력
		i++;
	}
	fputc('\n', fp); // 마지막에 개행 문자 대입
	fclose(fp);
}
```   
![결과13](https://github.com/HongryeolSeong/StudyC21/blob/main/img/fileres3.png "fileres3")
<br>
<br>

* 기본적으로 개방되는 표준 입출력 스트림 파일   
이 파일들을 이용하여 파일 포인터 없이 사용토록 함.   
1. stdin 표준 입력 스트림 키보드     
2. stdout 표준 출력 스트림 모니터   
3. stderr 표준 에러 스트림 모니터   
```C
int main()
{
	int ch;

	while (1)
	{
		// 예제 1. getchar()는 함수 내부적으로 stdin사용
		ch = getchar(); // 파일 포인터 사용x

		// 예제 2. 파일 포인터로 stdin을 받아 사용하는 fgetc()
		//ch = fgetc(stdin);

		if (ch == EOF)
		{
			break;
		}

		// 예제1. putchar()는 함수 내부적으로 stdout사용
		putchar(ch); // 파일 포인터 사용x

		// 예제 2. 파일 포인터로 stdout을 받아 사용하는 fputc()
		//fputc(ch, stdout);
	}
}
```   
위와 같이 표준 스트림 파일을 활용하여 따로 파일 포인터를 생성하지 않고   
키보드로 입력받고 모니터에 출력할 수 있음을 볼 수 있다.   
<br>

* 텍스트 / 바이너리 파일   
파일은 텍스트 파일과 바이너리 파일로 분류됨.   
아스키 코드값에 따라 읽거나 저장 시 -> 텍스트 파일 -> 개방 모드는 기존과 동일 or 't' 붙일 것   
그 외 -> 바이너리 파일 -> 개방 모드는 기존에 'b'를 붙일 것   
```C
int main()
{
	FILE* fp;
	// 10개의 아스키 문자
	int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	int i, res;

	// 아스키 문자들을 바이너리방식으로 a.txt에 출력
	fp = fopen("a.txt", "wb");
	for (i = 0; i < 10; i++)
	{
		fputc(ary[i], fp);
	}
	fclose(fp);

	// a.txt를 텍스트 파일로 읽어오기
	fp = fopen("a.txt", "rt");
	while (1)
	{
		res = fgetc(fp);
		if (res == EOF) break; // 아스키 코드 26 = -1 = EOF = ^Z
		printf("%4d", res);
	}
	fclose(fp);
}
```   
![결과14](https://github.com/HongryeolSeong/StudyC21/blob/main/img/fileres4.png "fileres4")   
위처럼 파일 형태와 개방 모드가 다를시 26을 아스키 코드로 읽어 EOF로 판단하여   
26 전에 있는 요소들만 읽게됨   
<br>

* '+' 개방모드, 여러가지 파일 함수   
기존 개방 모드에 '+'를 붙이면 프로그램 실행 중에 읽고 쓰고가 가능해짐   
1. fseek(FILE * Stream, long offset, int whence); : whence를 기준 offset만큼 파일의 버퍼에서 위치 지시사를 이동   
SEEK_SET : 파일의 처음 : 양수만 가능   
SEEK_CUR : 파일의 현재 위치 : 양수와 음수 가능   
SEEK_SET : 파일의 끝 : 음수만 가능   
2. rewind(FILE * Stream); = fseek(FILE * Stream, 0, SEEK_SET);   
3. feof(FILE * Stream); : 스트림 파일의 데이터를 모두 읽었는지 판단.   
파일의 끝 -> 0이 아닌 값   
파일의 끝x -> 0   
```C
int main()
{
	FILE* fp;
	char str[20];

	// a -> 파일 끝에 추가
	// + -> 데이터 기록 중 언제든지 파일 내용 읽을 수 있게함
	fp = fopen("a.txt", "a+");
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		printf("과일 이름 : ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0) // 경우 1. end 입력시 종료
		{
			break;
		}
		else if (strcmp(str, "list") == 0) // 경우 2. list 입력시 파일 내용 확인
		{
			fseek(fp, 0, SEEK_SET); // 버퍼의 위치 지시자를 맨 첨으로 이동
			while (1)
			{
				fgets(str, sizeof(str), fp); // 파일 내용 읽음
				if (feof(fp)) // 파일 내용 다 읽으면 종료
				{
					break;
				}
				printf("%s", str);
			}
		}
		else // 경우 3. 과일 입력시
		{
			fprintf(fp, "%s\n", str); // 입력한 과일을 파일에 출력
		}
	}
	fclose(fp);
}
```   
<br>

* fgets, fputs   
파일에 데이터를 한 줄씩("ABCD" + "\n")입력 또는 출력시 사용   
함수에 데이터의 크기를 인수로 주므로 메모리 침범 차단   
![결과15](https://github.com/HongryeolSeong/StudyC21/blob/main/img/fileres5.png "fileres5")   
```C
int main()
{
	FILE* ifp, * ofp;
	char str[80];
	char* res;

	ifp = fopen("a.txt", "r"); // 입력 받아올 파일의 포인터
	if (ifp == NULL)
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");  // 출력할 파일의 포인터
	while (1) // NULL 만날때까지 반복
	{
		//b.txt에 한 줄(str) 출력
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL) break;
		str[strlen(str) - 1] = '\0'; // 한 줄의 끝에 개행 문자를 제거하고 NULL문자 삽입
		fputs(str, ofp); // 한 줄 출력
		fputs(" ", ofp); // 한 줄 출력 후 이어서 스페이스 출력
	}

	fclose(ifp);
	fclose(ofp);
}
```   
![결과16](https://github.com/HongryeolSeong/StudyC21/blob/main/img/fileres6.png "fileres6")
<br>
<br>

* fscanf, fprintf   
여러 자료형을 가지는 여러 변수 출력시 사용   
```C
int main()
{
	FILE* ifp, * ofp;
	char name[20];
	int kor, eng, math;
	int total;
	double avg;
	int res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	if (ofp == NULL)
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
		if (res == EOF)
		{
			break;
		}
		total = kor + eng + math;
		avg = total / 3.0;
		fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
	}

	fclose(ifp);
	fclose(ofp);
}
```   
<br>

_fscanf를 활용한 18장 퀴즈   
로그인 프로그램_   
![결과17](https://github.com/HongryeolSeong/StudyC21/blob/main/img/fileres7.png "fileres7")   
```C
struct Login
{
	char id[80];
	int pw;
};

int main()
{
	FILE* fl;
	struct Login s1;
	char* id;
	char temp[80];
	int pw;
	int res;
	int check = 0;

	while (1)
	{
		printf("아이디를 입력하시오 : ");
		gets(temp);
		id = (char*)malloc(strlen(temp) + 1); // id 동적할당
		if (id == NULL)
		{
			printf("메모리가 부족합니다.");
			exit(1);
		}
		strcpy(id, temp);

		printf("패스워드를 입력하시오 : ");
		scanf("%d", &pw);

		fl = fopen("password.txt", "r"); // 로그인 정보 담긴 파일 개방
		if (fl == NULL)
		{
			printf("파일이 열리지 않았습니다.\n");
			return 1;
		}

		while (1)
		{
			// 개방한 파일에서 아이디와 비밀번호 입력받아 s1의 멤버에 각각 대입
			res = fscanf(fl, "%s%d", s1.id, &s1.pw); 
			if (res == EOF)
			{
				break;
			}

			if (strcmp(s1.id, id) == 0) // 파일의 id와 키보드로 입력받은 id가 같은 경우
			{
				if (s1.pw == pw) // 파일의 pw와 키보드로 입력받은 pw가 같은 경우
				{
					printf("로그인 되었습니다.\n");
					check = 1;
				}
				else // 파일의 pw와 키보드로 입력받은 pw가 다른 경우
				{
					printf("패스워드가 틀립니다.\n");
				}
			}
			else // 파일의 id와 키보드로 입력받은 id가 다른 경우
			{
				printf("아이디가 틀립니다.\n");
				getchar();
			}
		}

		if (check == 1) // 로그인이 된 경우
		{
			break;
		}

		printf("\n");

		fclose(fl); // 로그인 파일 닫기
		free(id);
	}
}
```   
![결과18](https://github.com/HongryeolSeong/StudyC21/blob/main/img/fileres8.png "fileres8")   
<br>

* 버퍼가 공유되어 발생되는 오류   
첫 번째 입력의 개행문자가 버퍼에 있다가 두 번째 입력에 공유되어 출력에 오류가 있는 경우이다.   
```C
int main()
{
	FILE* fp;
	int age;
	char name[20];

	fp = fopen("a.txt", "r");

	fscanf(fp, "%d", &age);
	while (fgetc(fp) != '\n') {} // 밑의 문제를 해결
	fgets(name, sizeof(name), fp); // 17"\n"에서 개행 문자가 바로 입력 돼버림

	printf("나이 : %d, 이름 : %s", age, name);
	fclose(fp);
}
```   
<br>

* fread()와 fwrite()   
입출력할 데이터의 크기와 개수를 인수로 받는 함수   
-> 대량의 데이터 사용시 유용   
-> 항상 바이너리 모드로 개방할 것   
```C
int main()
{
	FILE* afp, * bfp;
	int num = 10;
	int res;

	afp = fopen("a.txt", "wt");
	fprintf(afp, "%d", num);

	bfp = fopen("b.txt", "wb");
	fwrite(&num, sizeof(num), 1, bfp);

	fclose(afp);
	fclose(bfp);

	bfp = fopen("b.txt", "rb");
	fread(&res, sizeof(res), 1, bfp);
	printf("%d", res);

	fclose(bfp);
}
```   
