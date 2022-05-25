#include<stdio.h>
#include<string.h>
void main() {
	int data[100];//数字栈
	char c[100], a;//字符栈
	int v[1000];//结果
	int i = 0, flag = 0, j = 0,g=0,n;
	scanf_s("%d",&n);
	while (1)
	{
		if (flag == 0)
		{
			scanf_s("%d", &data[i]);
			i = i + 1;
			//	printf("::%d\n",i);
			flag = 1;
		}
		else {
			scanf_s("%c", &a);
			if (j == 0) c[j++] = a;
			else if (j > 0 && ((c[j - 1] == '-' || c[j - 1] == '+') && (a == '*' || a == '/')))//压栈
			{
				c[j++] = a;
			}
			else//出栈
			{
				//遇到#号时候可能会多次出栈，因为这里不考虑（），其他情况只出栈一次
				if (a != '#')
				{
					i = i - 2;
					switch (c[j - 1])
					{
					case '+': {data[i] = data[i] + data[i + 1];break;}
					case '-': {data[i] = data[i] - data[i + 1];break;}
					case '*': {data[i] = data[i] * data[i + 1];break;}
					case '/': {if (data[i + 1] != 0) data[i] = data[i] / data[i + 1]; break;}
					}
					j--;
					i++;
				}
				else
				while (a=='#'&&j > 0)
				{
					i = i - 2;
					switch (c[j - 1])
					{
					case '+': {data[i] = data[i] + data[i+1];break;}
					case '-': {data[i] = data[i]-data[i+1];break;}
					case '*': {data[i] = data[i] * data[i+1];break;}
					case '/': {if (data[i+1] != 0) data[i] = data[i] / data[i+1]; break;}
					}
					j--;
					i++;
				}
				c[j++] = a;
				if (c[j - 1] == '#')
				{
					v[g++]=data[i - 1];
					n--;
					i = 0;
					j = 0;
				}
				if (n <= 0)
				{ 
					v[g] = -1;
					break;
				}
			}
			flag = 0;
		}
		

	}
	g = 0;
	while (v[g] != -1)
	{
		printf("第%d个答案是%d\n",g+1,v[g]);
		g++;
	}
}