#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[25][25];
int main()
{
	int n;
	int x = 1;
	int y = 1;
	int i,j;
	int nx, ny;
	int d = 0;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	scanf("%d", &n);
	arr[1][1] = 1;
	for (i = 2;i <= n * n;i++)
	{
		nx = x + dx[d];
		ny = y + dy[d];
		if (nx<1 || nx>n || ny<1 || ny>n || arr[nx][ny] != 0)
		{
			d = (d + 1) % 4;
			nx = x + dx[d];
			ny = y + dy[d];
		}
		arr[nx][ny] = i;
		x = nx;
		y = ny;
	}
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}