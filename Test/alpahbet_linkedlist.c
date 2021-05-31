// 대소문자 분류_연결리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct node // 일반 노드
{
	int data;
	struct node* next;
} Node;

typedef struct // 헤더
{
	Node* head; // Node를 가리킬 수 있는 멤버
} HeadNode;

HeadNode* CreateHead(); // 헤더 생성
Node* RearInsertNode(HeadNode* header, int data); // 후위 추가
void SortNode(HeadNode* header); // 노드 정렬
void PrintNode(HeadNode* header); // 연결리스트 출력

int main()
{
	char input_ary[10];	// 입력한 알파벳을 담을 배열
	int i;
	int szu = 0;		// upperlist 노드 수
	int szl = 0;		// lowerlist 노드 수
	HeadNode* uh;		// upperlist 헤더
	HeadNode* lh;		// lowerlist 헤더

	// 1. 알파벳 입력
	gets(input_ary);

	// 2. 대/소문자 연결리스트의 헤더 생성
	uh = CreateHead();
	lh = CreateHead();

	// 3. 대소문자 분류 후 연결리스트 노드 생성 및 후위 추가
	for (i = 0; i < strlen(input_ary); i++)
	{
		if (input_ary[i] >= 'A' && input_ary[i] <= 'Z')
		{
			RearInsertNode(uh, input_ary[i]);
			szu++;
		}
		else if (input_ary[i] >= 'a' && input_ary[i] <= 'z')
		{
			RearInsertNode(lh, input_ary[i]);
			szl++;
		}
	}

	// 4. 대소문자 분류 후 결과
	PrintNode(uh);
	PrintNode(lh);

	// 5. 연결리스트별로 정렬 수행
	SortNode(uh, szu);
	SortNode(lh, szl);

	// 6. 최종 결과 확인
	PrintNode(uh);
	PrintNode(lh);

	return 0;
}

// 헤더 생성
HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL; // 역참조 방지. 역참조 : NULL이 h를 가리키는 경우

	return h;
}

// 후위 노드 추가
Node* RearInsertNode(HeadNode* header, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode != NULL)
	{
		// data와 next는 일단 초기화 수행
		newnode->data = data;
		newnode->next = NULL;

		// 새 노드와 전 노드의 연결 처리
		// 1. 헤더 바로 다음에 추가하는 경우
		if (header->head == NULL)
		{
			header->head = newnode;
		}
		// 2. 헤더 바로 다음 노드가 존재하는 경우
		else if (header->head != NULL)
		{
			Node* curr = header->head;	// curr은 첫 노드부터 시작
			while (curr->next != NULL)	// curr은 현 마지막 노드
			{
				curr = curr->next;		// 처음부터 순회하여 마지막 노드에 도달
			}
			curr->next = newnode;		// 새노드주소를 curr의 next에 대입
		}
	}
	return newnode;
}

// 노드 정렬
void SortNode(HeadNode* header,int sz)
{
	int i;
	Node* temp;	// swap을 위한 임시 구조체 포인터
	//Node* temp2;

	for (i = 0; i < sz; i++)					// 해당 연결리스트의 노드 수 만큼 반복 수행
	{
		Node* curr = header->head;				// curr은 첫 노드 부터 시작
		while (curr->next != NULL)
		{
			if (curr->data > curr->next->data)	// 해당 노드의 data가 다음 노드의 data보다 큰 경우
			{
				// 노드의 data값 swap 실행
				temp = curr->data;
				curr->data = curr->next->data;
				curr->next->data = temp;
			}
			curr = curr->next;					// curr은 다음 노드로 이동
		}
	}
	

	/*while (curr->next != NULL)
	{
		if (curr == header->head)
		{
			if (curr->data > curr->next->data)
			{
				header->head = curr->next;
				temp = curr->next->next;
				curr->next->next = curr;
				curr->next = temp;
			}
		}
		else if (curr != header->head)
		{
			if (curr->data > curr->next->data)
			{
				temp = curr->next->next;
				temp2 = curr->next;
				curr->next->next = curr;
				curr->next = temp;
				header->head = temp2;
			}
		}
	}*/
}

// 전체 출력
void PrintNode(HeadNode* header)
{
	int n = 1;
	Node* curr = header->head; // curr은 첫번째 노드로 시작

	// 현재 헤더만 있는 경우
	if (curr == NULL)
	{
		printf("출력 결과 : 현재 헤더만 존재합니다.\n");
		printf("\n");
	}
	// 헤더 이후 노드가 있는 경우
	else
	{
		while (curr != NULL)
		{
			//printf("출력 결과 : %d번째 노드의 값은 : %c\n", n++, curr->data);
			printf("%c", curr->data);
			curr = curr->next; // 마지막노드를 찾을때 까지 순회
		}
		printf("\n");
	}
}