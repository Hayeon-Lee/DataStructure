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

void initialize(node *H, node *T);
char add(node *H, node *T, int r, char e, int n);
char d_remove(node *H, node *T, int r, int n);
char get_e(node *H, node *T, int r, int n);
void print(node *H, node *T, int n);

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

//연결리스트 2번
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct NODE
{
	int coef;
	int exp;
	struct NODE *next;
}; typedef struct NODE node;

node * appendTerm(node * k, int c, int e);
node * addPoly(node *ik1, node *ik2);

int main()
{
	int n, c, e;
	node *k1 = NULL, *k2=NULL, *ik1, *ik2, *ire, *p;

	k1 = (node *)malloc(sizeof(node));
	k2 = (node *)malloc(sizeof(node));

	ik1 = k1;
	ik2 = k2;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &c, &e);
		ik1 = appendTerm(ik1, c, e);
	}

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &c, &e);
		ik2 = appendTerm(ik2, c, e);
	}

	ire = addPoly(k1, k2);
	p = ire;

	while (p->next != NULL) {
		p = p->next;
		printf(" %d %d", p->coef, p->exp);
	}
}

node * appendTerm(node *k, int c, int e)
{
	node *t=NULL;

	t = (node *)malloc(sizeof(node));

	t->coef = c;
	t->exp = e;
	t->next = NULL;
	k->next = t;

	return t;
}

node * addPoly(node *ik1, node *ik2)
{
	node *result = NULL, *i, *j, *k;
	int sum;

	result = (node *)malloc(sizeof(node));
	result->next = NULL;

	i = ik1;
	j = ik2;
	k = result;

	i = ik1->next;
	j = ik2->next;

	while ((i != NULL) && (j != NULL))
	{
		if (i->exp > j->exp)
		{
			k = appendTerm(k, i->coef, i->exp);
			i = i->next;
		}

		else if (i->exp < j->exp)
		{
			k = appendTerm(k, j->coef, j->exp);
			j = j->next;
		}

		else
		{
			sum = (i->coef + j->coef);
			
			if (sum != 0) k = appendTerm(k, sum, i->exp);
			i = i->next;
			j = j->next;
		}
	}

	while (i != NULL)
	{
		k = appendTerm(k, i->coef, i->exp);
		i = i->next;
	}

	while (j != NULL)
	{
		k = appendTerm(k, j->coef, j->exp);
		j = j->next;
	}

	return result;
}
