#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	struct NODE *left;
	struct NODE *right;
	int data;
}; typedef struct NODE node;

node ** makeRankarray(node **rankarray);
node * makeRootnode(int data, node *lchild, node *rchild);
void printTree(node **rankarray, int N);
void memoryfree(node **rankarray);

int main()
{
	int N, count = 8;
	node ** rankarray = NULL;
	rankarray = (node **)malloc(sizeof(node*) * 8);

	rankarray = makeRankarray(rankarray);

	scanf("%d", &N);
	printTree(rankarray, N);

	memoryfree(rankarray); //트리 노드들 메모리 해제
	free(rankarray); //rankarray 메모리해제
	return 0;
}

node ** makeRankarray(node **rankarray) //이걸 재귀로 짤 수 있을까요?
{
	rankarray[7] = makeRootnode(80, NULL, NULL);
	rankarray[6] = makeRootnode(130, NULL, NULL);
	rankarray[5] = makeRootnode(120, rankarray[6], rankarray[7]);
	rankarray[2] = makeRootnode(50, NULL, rankarray[5]);
	rankarray[4] = makeRootnode(90, NULL, NULL);
	rankarray[3] = makeRootnode(70, NULL, NULL);
	rankarray[1] = makeRootnode(30, rankarray[3], rankarray[4]);
	rankarray[0] = makeRootnode(20, rankarray[1], rankarray[2]);

	return rankarray;
}

node * makeRootnode(int elem, node *lchild, node *rchild)
{
	node *newnode = (node *)malloc(sizeof(node));

	newnode->data = elem;
	newnode->left = lchild;
	newnode->right = rchild;

	return newnode;
}

void printTree(node **rankarray, int N)
{
	if (N > 8)
	{
		printf("-1");
	}

	else
	{
		if (rankarray[N - 1]->right == NULL && rankarray[N - 1]->left == NULL)
			printf("%d", rankarray[N - 1]->data);

		else if (rankarray[N - 1]->right == NULL && rankarray[N - 1]->left != NULL)
			printf("%d %d", rankarray[N - 1]->data, rankarray[N - 1]->left->data);

		else if (rankarray[N - 1]->right != NULL && rankarray[N - 1]->left == NULL)
			printf("%d %d", rankarray[N - 1]->data, rankarray[N - 1]->right->data);

		else printf("%d %d %d", rankarray[N - 1]->data, rankarray[N - 1]->left->data, rankarray[N - 1]->right->data);
	}
}

void memoryfree(node **rankarray)
{
	for (int i = 0; i < 8; i++)
	{
		free(rankarray[i]);
	}
}
