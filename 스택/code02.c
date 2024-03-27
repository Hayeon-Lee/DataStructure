#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void push(char stack[], int *c_p, char temp);
void pop(char stack[], int *c_p);

int main()
{
	char arr[1000], stack[1000];
	int count = 0, *c_p = &count, total = 0, open_count = 0, close_count = 0;

	gets(arr);
	int l = strlen(arr);

	for (int i = 0; i <= l; i++)
	{
		if (arr[i] == '(') 
		{
			push(stack, c_p, '(');
			total++;
			open_count++;
		}
		else if (arr[i] == '{')
		{
			push(stack, c_p, '{');
			total++;
			open_count++;
		}
		else if (arr[i] == '[')
		{
			push(stack, c_p, '[');
			total++;
			open_count++;
		}
		
		else if (arr[i] == ')')
		{
			total++;
			close_count++;
			if (stack[(*(c_p)) - 1] == '(') pop(stack, c_p);
		}

		else if (arr[i] == '}')
		{
			total++;
			close_count++;
			if (stack[(*(c_p)) - 1] == '{') pop(stack, c_p);
		}

		else if (arr[i] == ']')
		{
			total++;
			close_count++;
			if (stack[(*(c_p)) - 1] == '[') pop(stack, c_p);
		}
	}

	if (count == 0 && (open_count==close_count)) printf("OK_%d", total);
	else printf("Wrong_%d", total);

	return 0;
}

void push(char stack[], int *c_p, char temp)
{
	stack[*(c_p)] = temp;
	(*(c_p))++;
}
void pop(char stack[], int *c_p)
{
	stack[(*(c_p)) - 1] = '\0';
	(*(c_p))--;
}
