#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct NODE
{
	int element;
	struct NODE *next;
	struct NODE *prev;
}; typedef struct NODE node;

node * add_front(node *deque, int e);
node * add_rear(node *deque, int e);
node * delete_front(node *deque);
node * delete_rear(node *rear);
void print_deque(node *deque);

int main()
{
	node *deque = NULL, *front=NULL, *rear = NULL;
	int n = 0, e = 0;
	char order[3];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%s", order);

		if (deque == NULL)
		{
			front = deque;
			rear = deque;
		}

		if (strcmp(order, "AF") == 0)
		{
			scanf("%d", &e);
			front = add_front(deque, e);
			deque = front;

			if (front->next == NULL) rear = front;
		}

		else if (strcmp(order, "AR") == 0)
		{
			scanf("%d", &e);
			rear = add_rear(rear, e);

			if (rear->prev == NULL)
			{
				front = rear;
				deque = rear;
			}
		}

		else if (strcmp(order, "DF") == 0)
		{
			if (deque == NULL)
			{
				printf("underflow");
				return 0;
			}
			else
			{
				front = delete_front(deque);
				deque = front;
				if (front == NULL) deque = NULL;
				else if (front->next == NULL) rear = front;
			}
		}

		else if (strcmp(order, "DR") == 0)
		{
			if (deque == NULL)
			{
				printf("underflow");
				return 0;
			}
			else
			{
				rear = delete_rear(rear);
				if (rear == NULL) deque = NULL;
				else if (rear->prev == NULL)
				{
					front = rear;
					deque = rear;
				}
			}
		}

		else if (strcmp(order, "P") == 0) print_deque(deque);
	}

	if (deque != NULL)
	{
		node *p = deque;
		while (1)
		{
			p = p->next;
			free(deque);
			deque=p;
			if(deque==NULL) break;
		}
	}
	else return 0;
}

node * add_front(node *deque, int e)
{
	if (deque == NULL)
	{
		node *newnode = (node *)malloc(sizeof(node));
		newnode->element = e;
		newnode->prev = NULL;
		newnode->next = NULL;

		return newnode;
	}

	else
	{
		node *newnode = (node *)malloc(sizeof(node));
		newnode->element = e;
		newnode->prev = NULL; 
		newnode->next = deque;
		deque->prev = newnode;

		return newnode; //새로운 deque의 앞이 됨
	}
}

node * add_rear(node *rear, int e)
{
	if (rear == NULL)
	{
		node *newnode = (node *)malloc(sizeof(node));
		newnode->element = e;
		newnode->prev = NULL;
		newnode->next = NULL;

		return newnode; //원소가 이것뿐이므로 newnode는 deque의 맨 앞이 될 수 있음
	}

	else
	{
		node *newnode = (node *)malloc(sizeof(node));
		newnode->element = e;
		newnode->prev = rear;
		newnode->next = NULL;
		rear->next = newnode;

		return newnode; //rear에 삽입했으므로 deque앞부분은 변하지 않음
	}
}

node * delete_front(node *deque)
{
	if (deque->next == NULL)
	{
		free(deque);
		return NULL;
	}

	else
	{
		node *p = deque->next;
		p->prev = NULL;
		free(deque);
		return p;
	}
}

node * delete_rear(node *rear)
{
	if (rear->prev == NULL)
	{
		free(rear);
		return NULL;
	}

	else
	{
		node *p = rear->prev;
		p->next = NULL;
		free(rear);
		return p;
	}
}

void print_deque(node *deque)
{
	node *p = deque;
	while (p != NULL) {
		printf(" %d", p->element);
		p = p->next;
	}
	printf("\n");
}
