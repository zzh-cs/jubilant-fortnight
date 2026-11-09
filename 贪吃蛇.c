#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char map[25][25];
int main()
{
	//这个是这个贪吃蛇的地图，20*20的地图，边界是#，里面是空格
	int i, j;
	for(i=1;i<=20;i++)
	{
		for (j = 1;j <= 20;j++)
		{
			if(j==1||j==20||i==1||i==20)
			{
				//这个是边界，表示蛇不能在里面移动
				map[i][j] = '#';
			}
			else
			{
				//这个是空格，表示蛇可以在里面移动
				map[i][j] = ' ';
			}
		}
	}
	//现在开始写这个贪吃蛇的游戏，首先我们需要定义蛇的初始位置和长度
	int snake_x[100], snake_y[100];
	int snake_length = 3;
	//123分别为这个蛇的蛇头身尾巴
	for (i = 1;i <= snake_length;i++)
	{
		snake_x[i] = 10;
		snake_y[i] = 10+(i-1);
	}
	//这个是蛇的初始位置，蛇的长度是3，蛇的初始位置是(10,10),(10,11),(10,12)
	//现在我想让这个蛇进行移动，首先我们需要定义蛇的移动方向，蛇的移动方向有四个，分别是上，下，左，右
	//我现在要进行一个名为方向数组的东西让这个蛇进行上下左右的移动。
	int arr[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
	//这个是蛇的移动方向，分别是上，下，左，右
	char key;
	
	int newsnake_x,newsnake_y;

	scanf(" %c", &key);

	//这个就是蛇的上下左右移动的代码，蛇的移动方向是根据键盘输入的w,s,a,d来进行移动的
	if (key == 'w')
	{
		newsnake_x= snake_x[1] + arr[0][0];
		newsnake_y= snake_y[1] + arr[0][1];
	}
	else if (key == 's')
	{
		newsnake_x = snake_x[1] + arr[1][0];
		newsnake_y= snake_y[1] + arr[1][1];
	}
	else if(key=='a')
	{
		newsnake_x = snake_x[1] + arr[2][0];
		newsnake_y= snake_y[1] + arr[2][1];

	}
	else if (key == 'd')
	{
		newsnake_x = snake_x[1] + arr[3][0];
		newsnake_y= snake_y[1] + arr[3][1];
	}
	else
	{
		printf("输入错误，请重新输入\n");
		return 0;
	}

	//更新蛇身的位置

	int k;

	for (k = snake_length;k > 1;k--)
		//k > 1 是因为 k = 1 是蛇头，它的位置要单独用"新位置"覆盖
		//如果循环跑到 k = 1，snake_x[1] 会被 snake_x[0] 覆盖
		//但 snake_x[0] 是垃圾值 → 蛇头跑到随机位置
	{
		snake_x[k] = snake_x[k - 1];
		snake_y[k] = snake_y[k - 1];
	}
	//最后来更新这个蛇头的位置也不算吧就是跟我原来写的蛇形方阵一样把这个蛇的位置进行更新
	snake_x[1] = newsnake_x;
	snake_y[1] = newsnake_y;
	//再次打印这个地图（为什么要再次进行打印这个）
	//因为进行蛇的移动后这个就和ppt一样动不了
	for (i = 1;i <= 20;i++)
	{
		for (j = 1;j <= 20;j++)
		{
			//这里是从这个整个数组里面找到我的蛇
			int issnake = 0;
			for (k = 1;k <= snake_length;k++)
			{
				if (snake_x[k] == i && snake_y[k] == j)
				{
					//找到我的蛇之后来进行一项将蛇身体进行打印的活动让它动起来
					issnake = 1;
					break;
				}
			}
			if (issnake == 1)
				//这个是来判断是不是这个蛇的位置
			{
				//蛇的身体
				printf("o");
			}
			else if (map[i][j] == '#')
			{
				//地图的边界
				printf("#");
			}
			else
			{
				//蛇的运动空间
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
