#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int isEmpty(int queue[], int q, int f, int r);
int isFull(int queue[], int q, int f, int r);
int insert_f(int queue[], int f, int r, int q, int in_N);
int delete_f(int queue[], int f, int r, int q);
void print_f(int queue[], int q);

int main()
{
	int *queue = NULL, q = 0, n = 0, in_N = 0, f = 0, r = 0, result=0, flag=0;
	char order;

	scanf("%d", &q); //큐의 크기
	scanf("%d", &n); //연산의 갯수

	queue = (int *)malloc(sizeof(int)*q); //큐 크기만큼의 배열 생성
	for (int i = 0; i < q; i++) queue[i] = 0; //배열 큐를 0으로 초기화

	for (int i = 0; i < n; i++) //명령 갯수만큼 반복문 작동
	{
		getchar();
		scanf("%c", &order); //명령 입력

		if (order == 'I')
		{
			scanf("%d", &in_N);
			result = insert_f(queue, f, r, q, in_N);
			if (result == -1) return 0;
			else r = result;
		}
		
		else if (order == 'D')
		{
			result = delete_f(queue, f, r, q);
			if (result == -1) return 0;
			else f = result;
		}

		else if (order == 'P') print_f(queue, q);
	}
	free(queue);
	return 0;
}

int isEmpty(int queue[], int q, int f, int r)
{
	if (r == f) return 2;
	else return 1;
}

int isFull(int queue[], int q, int f, int r)
{
	if (((r + 1) % q) == f) return 2;
	else return 1;
}

int insert_f(int queue[], int f, int r, int q, int in_N)
{
	int result = isFull(queue, q, f, r);

	if (result == 2)
	{
		printf("overflow");
		print_f(queue, q);
		return -1;
	}

	else
	{
		r = ((r + 1) % q);
		queue[r] = in_N;
		return r;
	}
}

int delete_f(int queue[], int f, int r, int q)
{
	int result = isEmpty(queue, q, f, r);

	if (result == 2)
	{
		printf("underflow");
		return -1;
	}

	else
	{
		queue[f + 1] = 0;
		f = ((f + 1) % q);
		return f;
	}
}

void print_f(int queue[], int q)
{
	for (int i = 0; i < q; i++) printf(" %d", queue[i]);
	printf("\n");
}
