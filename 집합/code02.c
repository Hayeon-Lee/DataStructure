#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct NODE
{
	int elem;
	struct NODE *next;
}; typedef struct NODE node;

void initialize(node *H);
node * makegroup(node *H, int *ar, int size);
node * unionf(node *AH, node *BH);
node * intersectf(node *AH, node *BH);
void removeFirst(node *H);

int main()
{
	int sizeA, sizeB, *na, *nb;
	node *ugroupAHead = NULL, *ugroupBHead = NULL, *union_groupCHead, *intersect_groupCHead, *p;
	node *igroupAHead = NULL, *igroupBHead = NULL;

	ugroupAHead = (node *)malloc(sizeof(node));
	ugroupBHead = (node *)malloc(sizeof(node));

	igroupAHead = (node *)malloc(sizeof(node));
	igroupBHead = (node *)malloc(sizeof(node));

	scanf("%d", &sizeA);
	na = (int *)malloc(sizeof(int)*sizeA);
	for (int i = 0; i < sizeA; i++) scanf("%d", na + i);

	scanf("%d", &sizeB);
	nb = (int *)malloc(sizeof(int)*sizeB);
	for (int i = 0; i < sizeB; i++) scanf("%d", nb + i);

	initialize(ugroupAHead);
	initialize(ugroupBHead);

	initialize(igroupAHead);
	initialize(igroupBHead);//노드 초기화

	ugroupAHead = makegroup(ugroupAHead, na, sizeA);
	ugroupBHead = makegroup(ugroupBHead, nb, sizeB);

	igroupAHead = makegroup(igroupAHead, na, sizeA);
	igroupBHead = makegroup(igroupBHead, nb, sizeB);

	union_groupCHead = unionf(ugroupAHead, ugroupBHead);
	intersect_groupCHead = intersectf(igroupAHead, igroupBHead);

	if (union_groupCHead->next != NULL)  p = union_groupCHead->next;

	if (union_groupCHead->next == NULL) printf(" 0");
	else {
		while (1)
		{
			printf(" %d", p->elem);
			if (p->next == NULL) break;
			p = p->next;
		}
	}

	printf("\n");

	if (intersect_groupCHead->next != NULL) p = intersect_groupCHead->next;

	if (intersect_groupCHead->next == NULL) printf(" 0");
	else {
		while (1)
		{
			printf(" %d", p->elem);
			if (p->next == NULL) break;
			p = p->next;
		}
	}

	free(ugroupAHead);
	free(ugroupBHead);
	free(igroupAHead);
	free(igroupBHead); //중간중간 전부 해제해서 헤더노드만 삭제하면 됨

	free(na);
	free(nb); //숫자 저장했던 배열

	p = union_groupCHead;
	while (p != NULL)
	{
		p = union_groupCHead->next;
		free(union_groupCHead);
		union_groupCHead = p;
	} //합집합 메모리 해제

	p = intersect_groupCHead;
	while (p != NULL)
	{
		p = intersect_groupCHead->next;
		free(intersect_groupCHead);
		intersect_groupCHead = p;
	} //교집합 메모리 해제
	return 0;
}

void initialize(node *H)
{
	H->elem = NULL;
	H->next = NULL;
}

node * makegroup(node *H, int *ar, int size)
{
	node *p = NULL;

	for (int i = 0; i < size; i++)
	{
		node *newnode = (node *)malloc(sizeof(node));
		if (i == 0) H->next = newnode;
		else p->next = newnode;
		newnode->elem = ar[i];
		p = newnode;
	}

	if (size != 0) p->next = NULL;

	return H;
}

void removeFirst(node *H)
{
	node *p = H->next;
	if (p->next!=NULL) H->next = p->next;
	else H->next = NULL;

	free(p);
}

node * unionf(node *AH, node *BH)
{
	node *p = NULL, *ap=AH, *bp=BH;

	node *groupCHead = (node *)malloc(sizeof(node));
	initialize(groupCHead);

	while (AH->next != NULL && BH->next != NULL)
	{
		node *newnode = (node *)malloc(sizeof(node));
		if (groupCHead->next == NULL) groupCHead->next = newnode;
		else p->next = newnode;

		ap = AH->next;
		bp = BH->next;

		if (ap->elem < bp->elem)
		{
			newnode->elem = ap->elem;
			p = newnode;
			removeFirst(AH);
		}

		else if (ap->elem > bp->elem)
		{
			newnode->elem = bp->elem;
			p = newnode;
			removeFirst(BH);
		}

		else
		{
			newnode->elem = ap->elem;
			p = newnode;
			removeFirst(AH);
			removeFirst(BH);
		}
	}

	while (AH->next != NULL)
	{
		node *newnode = (node *)malloc(sizeof(node));
		if (groupCHead->next == NULL) groupCHead->next = newnode;
		else p->next = newnode;

		ap = AH->next;
		newnode->elem = ap->elem;
		p = newnode;
		removeFirst(AH);
	}

	while (BH->next != NULL)
	{
		node *newnode = (node *)malloc(sizeof(node));
		if (groupCHead->next == NULL) groupCHead->next = newnode;
		else p->next = newnode;

		bp = BH->next;
		newnode->elem = bp->elem;
		p = newnode;
		removeFirst(BH);
	}

	if (groupCHead->next!=NULL) p->next = NULL;
	return groupCHead;
}

node * intersectf(node *AH, node *BH)
{
	node *p = NULL, *ap = AH, *bp = BH;

	node *groupCHead = (node *)malloc(sizeof(node));
	initialize(groupCHead);

	while (AH->next != NULL && BH->next != NULL)
	{
		ap = AH->next;
		bp = BH->next;

		if (ap->elem < bp->elem) removeFirst(AH);

		else if (ap->elem > bp->elem) removeFirst(BH);

		else
		{
			node *newnode = (node *)malloc(sizeof(node));
			if (groupCHead->next == NULL) groupCHead->next = newnode;
			else p->next = newnode;
			newnode->elem = ap->elem;

			p = newnode;
			removeFirst(AH);
			removeFirst(BH);
		}
	}
	while (AH->next != NULL) removeFirst(AH);

	while (BH->next != NULL) removeFirst(BH);

	if(groupCHead->next!=NULL) p->next = NULL;
	return groupCHead;
}
