#include <stdio.h>

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

	a.next = &b;
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