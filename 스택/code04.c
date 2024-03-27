#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int cal_N, stack[101] = { -999 }, t = -1;
	char **cal, num = 0;

	scanf("%d", &cal_N);
	cal = (char **)malloc(sizeof(char *)*cal_N);
	for (int i = 0; i < cal_N; i++) cal[i] = (char *)malloc(sizeof(char)*101);

	for (int i = 0; i < cal_N; i++) scanf("%s", cal[i]);

	for (int i = 0; i < cal_N; i++)
	{
		for (int j = 0; j < strlen(cal[i]); j++)
		{
			num = cal[i][j];
			if(num=='+'||num=='-'||num=='*'||num=='/')
			{
				if (num == '+')
				{
					if (stack[t - 1] != -999 &&stack[t] != -999)
					{
						stack[t - 1] += stack[t];
						stack[t] = -999 ;
						t--;
					}
				}
				else if (num == '-')
				{
					if (stack[t - 1] != -999 &&stack[t] != -999 )
					{
						stack[t - 1] -= stack[t];
						stack[t] = -999;
						t--;
					}
				}
				else if (num == '*')
				{
					if (stack[t - 1] != -999 &&stack[t] != -999 )
					{
						stack[t - 1] *= stack[t];
						stack[t] = -999 ;
						t--;
					}
				}
				else if (num == '/')
				{
					if (stack[t - 1] != -999 &&stack[t] != -999)
					{
						stack[t - 1] /= stack[t];
						stack[t] = -999;
						t--;
					}
				}
			}
			else if (atoi(&num) >= 0 && atoi(&num) <= 9)
			{
				t++;
				stack[t] = atoi(&num);
			}
		}
		printf("%d\n", stack[0]);
		for (int k = 0; k < 101; k++)stack[k] = -999;
		t = -1;
	}

	for (int i = 0; i < cal_N; i++) free(cal[i]);
	free(cal);
	return 0;
}
