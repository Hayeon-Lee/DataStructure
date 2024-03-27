#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *stack, char t, int *c_p); //stack의 top에 데이터를 추가한다.
char pop(char *stack, int *c_p); //stack의 top에 있는 데이터를 반환하고 stack에서 제거한다.
void peek(char *stack, int *c_p); //stack의 top에 있는 데이터를 화면에 출력한다.
void duplicate(char *stack, int *c_p); //stack의 top에 있는 데이터를 pop 한 뒤, 두 번 push 한다
void upRotate(char *stack, int *c_p, int R_N); //stack의 맨 위 n개의 데이터를 회전시킨다.
void downRotate(char *stack, int *c_p, int R_N); //stack의 맨 아래 n개의 데이터를 회전시킨다.
void print(char *stack, int *c_p); //stack의 모든 데이터를 top에서부터 순서대로 공백 없이 출력한다.

int main()
{
	int N, order_N, R_N, count = 0, *c_p = &count;
	char *stack, order[6], temp;

	scanf("%d", &N);
	getchar();
	scanf("%d", &order_N);

	stack = (char *)malloc(sizeof(char)*N);

	for (int i = 0; i < order_N; i++)
	{
		scanf("%s", order);
		
		if (strcmp(order, "PUSH")==0)
		{
			getchar();
			scanf("%c", &temp);
			if (N == count) printf("Stack FULL\n");
			else push(stack, temp, c_p);
		}

		else if (strcmp(order, "POP") == 0)
		{
			if (count == 0) printf("Stack Empty\n");
			else pop(stack, c_p);
		}

		else if (strcmp(order, "PEEK") == 0)
		{
			if (count == 0) printf("Stack Empty\n");
			else peek(stack, c_p);
		}

		else if (strcmp(order, "DUP") == 0)
		{
			if (count == N) printf("Stack FULL\n");
			else duplicate(stack, c_p);
		}

		else if (strcmp(order, "UpR") == 0)
		{
			scanf("%d", &R_N);
			if (R_N > count) continue;
			else upRotate(stack, c_p, R_N);
		}

		else if (strcmp(order, "DownR") == 0)
		{
			scanf("%d", &R_N);
			if (R_N > count) continue;
			else downRotate(stack, c_p, R_N);
		}

		else if (strcmp(order, "PRINT") == 0)
		{
			print(stack, c_p);
			printf("\n");
		}
	}

	free(stack);
	return 0;
}

void push(char *stack, char t, int *c_p)
{
	stack[(*(c_p))] = t;
	(*(c_p))++;
}

char pop(char *stack, int *c_p)
{
	char output = stack[(*(c_p)) - 1];
	stack[(*(c_p))-1] = '\0';
	(*(c_p))--;

	return output;
}
void peek(char *stack, int *c_p)
{
	printf("%c", stack[(*(c_p))-1]);
}
void duplicate(char *stack, int *c_p)
{
	stack[(*(c_p))] = stack[(*(c_p)) - 1];
	(*(c_p))++;
}
void upRotate(char *stack, int *c_p, int R_N)
{
	char temp = stack[(*(c_p))-1];

	for (int i = (*(c_p))-1; i > (*(c_p))-R_N; i--)
	{
		stack[i] = stack[i - 1];
	}
	stack[*(c_p)-R_N] = temp;
}
void downRotate(char *stack, int *c_p, int R_N)
{
	char temp = stack[*(c_p)-R_N];
	
	for (int i = (*(c_p)) - R_N; i < (*(c_p)) - 1; i++)
	{
		stack[i] = stack[i + 1];
	}
	stack[(*(c_p))-1] = temp;
}
void print(char *stack, int *c_p)
{
	for (int i = (*(c_p))-1; i >= 0; i--) printf("%c", stack[i]);
}
