#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char **cal, stack[101] = { 0 };
	int cal_N, t = -1, flag = 0;

	scanf("%d", &cal_N);//갯수 입력

	cal = (char **)malloc(sizeof(char *)*cal_N);//세로줄 할당
	for (int i = 0; i < cal_N; i++) cal[i] = (char *)malloc(sizeof(char) * 101);//가로줄 할당

	for (int i = 0; i < cal_N; i++) scanf("%s", cal[i]);

	for (int i = 0; i < cal_N; i++)
	{
		for (int j = 0; j <= strlen(cal[i]); j++)
		{
			if (j == 0)
			{
				if (cal[i][0] == '+' || cal[i][0] == '-')
				{
					flag = 1;
					continue;
				}
			}

			if (j >= 1)
			{
				if (cal[i][j] == '+' || cal[i][j] == '-')
				{
					if (cal[i][j + 1] >= 'A'&&cal[i][j + 1] <= 'Z'||cal[i][j+1]=='-'||cal[i][j+1]=='+') {
						if (cal[i][j - 1] == '+' || cal[i][j - 1] == '-' || cal[i][j - 1] == '/' || cal[i][j - 1] == '*'||cal[i][j-1]=='>'||cal[i][j-1]=='<'||cal[i][j-1]=='&'||cal[i][j-1]=='|')
						{
							flag = 1;
							continue;
						}
					}
				}
				if (cal[i][j] == '!')
				{
					if (cal[i][j + 1] >= 'A'&&cal[i][j + 1] <= 'Z' || cal[i][j + 1] == '-' || cal[i][j + 1] == '+')
						if (cal[i][j - 1] >= 'A'&&cal[i][j - 1] <= 'Z')
						{
							flag = 2;
							continue;
						}
				}
			}

			if (cal[i][j] <= 'Z'&&cal[i][j] >= 'A')
			{
				printf("%c", cal[i][j]);
				if (flag == 1) printf("%c", cal[i][j - 1]);
				if (flag == 2) printf("%c", cal[i][j - 2]);
				flag = 0;
			}
			else
			{
				switch (cal[i][j])
				{
				case '!':
					if (t == -1)
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '!')
					{
						while (1) {
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '!') break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

				case '*': case '/':
					if (t == -1)
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '*' || stack[t] == '/')
					{
						while (1) {
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '*' || stack[t] != '/') break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '!')
					{
						while (1) {
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '!'&&stack[t] != '*'&&stack[t] != '/') break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

				case '+': case'-':
					if (t == -1)
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '+' || stack[t] == '-')
					{
						while (1) {
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '+' || stack[t] != '-') break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '!' || stack[t] == '*' || stack[t] == '/')
					{
						while (1)
						{
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '!'&&stack[t] != '*'&&stack[t] != '/'&&stack[t] != '+'&&stack[t] != '-')break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

				case '>': case'<':
					if (t == -1)
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '>' || stack[t] == '<')
					{
						while (1) {
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '<' || stack[t] != '>') break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '!' || stack[t] == '*' || stack[t] == '/' || stack[t] == '+' || stack[t] == '-')
					{
						while (1)
						{
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '!'&&stack[t] != '*'&&stack[t] != '/'&&stack[t] != '+'&&stack[t] != '-'&&stack[t] != '>'&&stack[t] != '<') break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

				case '&':
					if (t == -1)
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '&')
					{
						if (stack[t - 1] == '&')
						{
							while (1) {
								printf("%c", stack[t]);
								stack[t] = 0;
								t--;
								if (stack[t] != '!'&&stack[t] != '*'&&stack[t] != '/'&&stack[t] != '+'&&stack[t] != '-'&&stack[t] != '>'&&stack[t] != '<'&&stack[t] != '&') break;
							}
							t++;
							stack[t] = cal[i][j];
							break;
						}

						else
						{
							t++;
							stack[t] = cal[i][j];
							break;
						}
					}

					else if (stack[t] == '!' || stack[t] == '*' || stack[t] == '/' || stack[t] == '+' || stack[t] == '-'||stack[t]=='<'||stack[t]=='>')
					{
						while (1)
						{
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '!'&&stack[t] != '*'&&stack[t] != '/' && stack[t] != '+'&&stack[t] != '-' &&stack[t] != '>'&&stack[t] != '<'&&stack[t] != '&') break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

				case '|':
					if (t == -1)
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else if (stack[t] == '|')
					{
						if (stack[t - 1] == '|')
						{
							while (1) {
								printf("%c", stack[t]);
								stack[t] = 0;
								t--;
								if (stack[t] != '!'&&stack[t] != '*'&&stack[t] != '/'&&stack[t] != '+'&&stack[t] != '-'&&stack[t] != '>'&&stack[t] != '<'&&stack[t] != '&'&&stack[t]!='|') break;
							}
							t++;
							stack[t] = cal[i][j];
							break;
						}

						else
						{
							t++;
							stack[t] = cal[i][j];
							break;
						}
					}

					else if (stack[t] == '!' || stack[t] == '*' || stack[t] == '/' || stack[t] == '+' || stack[t] == '-' || stack[t] == '&')
					{
						while (1)
						{
							printf("%c", stack[t]);
							stack[t] = 0;
							t--;
							if (stack[t] != '!'&&stack[t] != '*'&&stack[t] != '/' && stack[t] != '+'&&stack[t] != '-' &&stack[t] != '>'&&stack[t] != '<'&&stack[t] != '&'&&stack[t] != '|') break;
						}
						t++;
						stack[t] = cal[i][j];
						break;
					}

					else
					{
						t++;
						stack[t] = cal[i][j];
						break;
					}
				case '(':
					t++;
					stack[t] = cal[i][j];
					break;

				case ')':
					while (stack[t] != '(')
					{
						printf("%c", stack[t]);
						t--;
					}
					stack[t] = 0;
					t--;
					break;
				}
			}
		}
		if (t != -1)
		{
			for (int p = t; p > -1; p--)
			{
				printf("%c", stack[p]);
			}

		}
		for (int k = 0; k < 101; k++) stack[k] = 0;
		t = -1;
		printf("\n");
	}

	for (int i = 0; i < cal_N; i++) free(cal[i]);
	free(cal);
}
