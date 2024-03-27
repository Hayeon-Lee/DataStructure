/*
헤더 단일 연결리스트로 다항식을 표현하고 다항식의 덧셈을 수행하라

다항식의 항의 개수를 입력받고, 다항식 정보를 입력 받는다.

5 3 3 2 3 1 의 경우 5x^3 + 3x^2 + 3x 를 의미한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct NODE
{
	int coef;
	int exp;
	struct NODE *next;
}; typedef struct NODE node;

node * appendTerm(node * k, int c, int e); //이전 노드, 계수, 지수
node * addPoly(node *ik1, node *ik2); //두 개의 단일 연결리스트

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
