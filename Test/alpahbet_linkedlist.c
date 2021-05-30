#include <stdio.h>
#include <stdlib.h>

typedef struct node // �Ϲ� ���
{
	int data;
	struct node* next;
} Node;

typedef struct // ���
{
	Node* head; // Node�� ����ų �� �ִ� ���
} HeadNode;

HeadNode* CreateHead(); // ��� ����
Node* RearInsertNode(HeadNode* header, int data); // ���� �߰�
void SortNode(HeadNode* header);
void PrintNode(HeadNode* header); // ���Ḯ��Ʈ ���

int main()
{
	char input_ary[10];
	int i;
	int szu = 0;	// upperlist ��� ��
	int szl = 0;	// lowerlist ��� ��
	HeadNode* uh;	// upperlist ���
	HeadNode* lh;	// lowerlist ���

	uh = CreateHead();
	lh = CreateHead();
	gets(input_ary);

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

	PrintNode(uh);
	PrintNode(lh);

	SortNode(uh);
	SortNode(lh);

	PrintNode(uh);
	PrintNode(lh);

	return 0;
}

// ��� ����
HeadNode* CreateHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL; // ������ ����. ������ : NULL�� h�� ����Ű�� ���

	return h;
}

// ���� ��� �߰�
Node* RearInsertNode(HeadNode* header, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode != NULL)
	{
		// data�� next�� �ϴ� �ʱ�ȭ ��
		newnode->data = data;
		newnode->next = NULL;

		// �� ���� �� ����� ���� ó��
		// 1. ��� �ٷ� ������ �߰��ϴ� ���
		if (header->head == NULL)
		{
			header->head = newnode;
		}
		// 2. ��� �ٷ� ���� ��尡 �����ϴ� ���
		else if (header->head != NULL)
		{
			Node* curr = header->head;
			while (curr->next != NULL) // curr�� �� ������ ���
			{
				curr = curr->next; // ó������ ��ȸ�Ͽ� ������ ��忡 ����
			}
			curr->next = newnode; // ������ּҸ� curr�� next�� ����
		}
	}
	return newnode;
}

// ��� ����
void SortNode(HeadNode* header)
{
	Node* temp;
	Node* temp2;
	Node* curr = header->head;
	while (curr->next != NULL)
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
		/*else if (curr != header->head)
		{
			if (curr->data > curr->next->data)
			{
				temp = curr->next->next;
				temp2 = curr->next;
				curr->next->next = curr;
				curr->next = temp;
				header->head = temp2;
			}
		}*/
	}
}

// ��ü ���
void PrintNode(HeadNode* header)
{
	int n = 1;
	Node* curr = header->head; // curr�� ù��° ���� ����

	// ���� ����� �ִ� ���
	if (curr == NULL)
	{
		printf("��� ��� : ���� ����� �����մϴ�.\n");
		printf("\n");
	}
	// ��� ���� ��尡 �ִ� ���
	else
	{
		while (curr != NULL)
		{
			//printf("��� ��� : %d��° ����� ���� : %c\n", n++, curr->data);
			printf("%c", curr->data);
			curr = curr->next; // ��������带 ã���� ���� ��ȸ
		}
		printf("\n");
	}
}