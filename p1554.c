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
		//这里需要把t赋值为i，因为i会改变，t是用来计算每个数字的
		//我最开始的时候写成了while(i>0)，这样会导致i的值改变，最后i的值会变成0，导致循环结束
		//导致陷入死循环，最后程序崩溃
		int t = i;
		while (t > 0)
		{
			//需要注意的是在循环中不要对i进行操作，因为i是循环变量，改变它会导致循环出错
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