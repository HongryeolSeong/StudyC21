#include <stdio.h>

struct list
{
	int num;
	struct list* next; // ����ü �ڽ��� ����Ű�� ������ next
};

int main()
{
	struct list a = { 10, 0 }, b = { 20, 0 }, c = { 30, 0 };
	struct list* head = &a, * current;
	// ����ü a�� ����Ű�� head�� list����ü�� ����Ű�� current ������

	a.next = &b;
	b.next = &c;

	printf("head->num : %d\n", head->num);
	printf("head->next->num : %d\n", head->next->num);

	printf("list all : ");
	current = head;
	while (current != NULL) // ���� ����Ʈ ����
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

	return 0;
}