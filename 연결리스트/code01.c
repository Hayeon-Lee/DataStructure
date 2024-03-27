//연결리스트 1번
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct NODE
{
	char elem;
	struct NODE *prev;
	struct NODE *next;
}; typedef struct NODE node;

void initialize(node *H, node *T); //이중연결리스트 초기화 (초기 두 노드 서로 연결)
char add(node *H, node *T, int r, char e, int n); //리스트의 순위 r에 원소 e를 추가한다.
char d_remove(node *H, node *T, int r, int n); //리스트의 순위 r에 위치한 원소를 삭제한다.
char get_e(node *H, node *T, int r, int n); //리스트의 순위 r에 위치한 원소를 반환한다.
void print(node *H, node *T, int n); //리스트의 모든 원소를 저장 순서대로 공백없이 출력한다.

int main()
{
	node *H = NULL, *T = NULL;
	int n = 0, total, r;
	char order, e;

	H = (node *)malloc(sizeof(node));
	T = (node *)malloc(sizeof(node));	

	initialize(H, T);
	scanf("%d", &total);
	getchar();

	for (int i = 0; i < total; i++)
	{
		scanf("%c", &order);
		getchar();

		if (order == 'A')
		{
			scanf("%d %c", &r, &e);
			getchar();
			n++;
			if (add(H, T, r, e, n) == ' ') {
				n--;
			}
		}
		if (order == 'D')
		{
			scanf("%d", &r);
			getchar();
			if (d_remove(H, T, r, n) != ' ') n--;
		}

		if (order == 'G')
		{
			scanf("%d", &r);
			getchar();
			if (get_e(H, T, r, n) != ' ')
				printf("%c\n", get_e(H, T, r, n));
		}

		if (order == 'P')
		{
			print(H, T, n);
		}
	}

	return 0;
}
void initialize(node *H, node *T)
{
	H->next = T;
	H->prev = NULL;
	T->prev = H;
	T->next = NULL;

	return;
}

char get_e(node *H, node *T, int r, int n)
{
	node *p;
	if (r<1 || r>n)
	{
		printf("invalid position\n");
		return ' ';
	}
	p = H;
	for (int i = 1; i <= r; i++)
	{
		p = p->next;
	}

	return p->elem;
}

void print(node *H, node *T, int n)
{
	node *p = H;
	for (int i = 1; i <= n; i++)
	{
		p = p->next;
		printf("%c", p->elem);
	}

	if (n != 0) printf("\n");
}

char add(node *H, node *T, int r, char e, int n)
{
	node *p = H;
	node *Newnode = (node *)malloc(sizeof(node));

	Newnode->elem = e;

	if (r > n || r < 1)
	{
		printf("invalid position\n");
		return ' ';
	}

	for (int i = 1; i <= r; i++)
	{
		p = p->next;
	}

	if (r == 1 && H->next == T)
	{
		H->next = Newnode;
		Newnode->prev = H;
		Newnode->next = T;
		T->prev = Newnode;
		return 'a';
	}

	else if (p == T)
	{
		Newnode->prev = p->prev;
		Newnode->next = T;
		(p->prev)->next = Newnode;
		T->prev = Newnode;
		return 'a';
	}
	else
	{
		Newnode->prev = p->prev;
		Newnode->next = p;
		(p->prev)->next = Newnode;
		(Newnode->next)->prev = Newnode;
		return 'a';
	}
}
char d_remove(node *H, node *T, int r, int n)
{
	node *p = H;

	if (r > n || r < 1) {
		printf("invalid position\n");
		return ' ';
	}

	for (int i = 1; i <= r; i++)
	{
		p = p->next;
	}

	(p->prev)->next = (p->next);
	(p->next)->prev = (p->prev);

	return 'a';
}

