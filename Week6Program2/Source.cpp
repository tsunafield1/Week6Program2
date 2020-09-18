#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct pad
{
	char a[5];
};

void strcpy(char*, const char*);
int strlen(char*);
int strlen(const char*);

int main()
{
	int n,h,v,m,index=0,row,col;
	pad num[4][4];
	strcpy(num[0][1].a,"ABC");
	strcpy(num[0][2].a , "DEF");
	strcpy(num[1][0].a , "GHI");
	strcpy(num[1][1].a , "JKL");
	strcpy(num[1][2].a , "MNO");
	strcpy(num[2][0].a , "PQRS");
	strcpy(num[2][1].a , "TUV");
	strcpy(num[2][2].a , "WXYZ");
	char ans[82];
	scanf("%d", &n);
	scanf("%d %d", &h, &m);
	if (h != 1)
	{
		row = (h - 1) / 3;
		col = (h - 1) % 3;
		m = (m - 1) % strlen(num[row][col].a);
		ans[index] = num[row][col].a[m];
		index++;
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %d", &h,&v, &m);
		row += v;
		col += h;
		if (row == 0 && col == 0)
		{
			for (int j = 0; j < m; j++)
			{
				if (index == 0)break;
				else
				{
					index--;
				}
			}
		}
		else
		{
			m = (m - 1) % strlen(num[row][col].a);
			ans[index] = num[row][col].a[m];
			index++;
		}
	}
	if (index != 0)
	{
		ans[index] = '\0';
		printf("%s", ans);
	}
	else printf("null");
}

void strcpy(char a[], const char b[])
{
	int i;
	for (i = 0; i < strlen(b); i++)
	{
		a[i] = b[i];
	}
	a[i] = '\0';
}

int strlen(char a[])
{
	int i;
	for (i = -1; a[i+1] != '\0'; i++);
	return i+1;
}

int strlen(const char a[])
{
	int i;
	for (i = -1; a[i + 1] != '\0'; i++);
	return i + 1;
}