#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct NODE
{
	int elem;
	struct NODE *next;
}; typedef struct NODE node;

void initialize(node *A, node *B); //A,B 각각 초기화
node *makegroup(node *H, int size);
int subset(node *A, node *B, int sizeA, int sizeB);
int member(node *A, int B_elem, int sizeA, int sizeB);

int main()
{
	int sizeA, sizeB, result;
	node *A = NULL, *B = NULL, *p;

	A = (node *)malloc(sizeof(node));
	B = (node *)malloc(sizeof(node));
	initialize(A, B);

	scanf("%d", &sizeA);
	A = makegroup(A, sizeA); //집합 A생성

	scanf("%d", &sizeB);
	B = makegroup(B, sizeB); //집합 B생성

	result = subset(A, B, sizeA, sizeB);
	printf("%d", result);

	p = A;
	while (A->next != NULL)
	{
		p = A->next;
		free(A);
		A = p;
	} //A집합 메모리 해제

	p = B;
	while (B->next != NULL)
	{
		p = B->next;
		free(B);
		B = p;
	} //B집힙 메모리 해제
}

void initialize(node *A, node *B)
{
	A->elem = NULL;
	A->next = NULL;

	B->elem = NULL;
	B->next = NULL;
}

node * makegroup(node *H, int size)
{
	node *p = H;

	int *ar = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++) scanf("%d", ar + i); //집합 원소 입력

	if (size != 0)	H->elem = ar[0];
	else return H;

	for (int i = 1; i < size; i++)
	{
		node *newnode = (node*)malloc(sizeof(node));
		p->next = newnode;
		newnode->elem = ar[i];
		p = p->next;
	}
	
	p->next = NULL;
	free(ar); //원소저장배열 메모리 해제

	return H;
}

int subset(node *A, node *B, int sizeA, int sizeB)
{
	if (A->elem == NULL) return 0;

	while (1)
	{
		if (member(A, B->elem, sizeA, sizeB) == 1)
		{
			if (A->next == NULL) return 0;
			else
			{
				A = A->next;
				if (B->next == NULL) return A->elem;
				B = B->next;
			}
		}
		else
		{
			if (B->next == NULL && sizeA<sizeB) return A->elem;
			else if (sizeA >= sizeB) return A->elem;
			else B = B->next;
		}
	}
}

int member(node *A, int B_elem, int sizeA, int sizeB)
{
	while (1) {
		if (A->elem < B_elem)
		{
			if (A->next == NULL) return 0;
			else
			{
				if (sizeA >= sizeB) return 0;
				else A = A->next;
			}
		}
		else if (A->elem > B_elem) return 0;
		else return 1;
	}
}
