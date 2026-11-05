#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[10];
int main()
{
	int m, n;
	int i;
	scanf("%d %d", &m, &n);
	for (i = m;i <= n;i++)
	{
		int t = i;
		while (t > 0)
		{
			int temp =t  % 10;
			arr[temp]++;
			t = t / 10;
		}
	}
	for (i = 0;i < 10;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}