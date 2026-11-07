#include<stdio.h>
#include<stdlib.h>
int arr[105][105];
//这个跟蛇形方阵不是很一样蛇形方阵是不断移动遇到障碍物就会改变方向，而这个是固定的火把和萤石，所以我们只需要计算每个火把和萤石的范围，然后标记这个范围内的点就行了
//蛇形方阵还需要这个申请方向数组
int main()
{
	int i, j;
	int s;
	int count = 0;
	int x, y;
	int nx, ny;
	int dx, dy;
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		for (dx = -2;dx <= 2;dx++)
		{
			for (dy = -2; dy <= 2; dy++)
			{
				s = abs(dx) + abs(dy);
				//这个是为什么要用abs()函数呢？因为我们要计算曼哈顿距离，曼哈顿距离是指在一个网格中，从一个点到另一个点的距离，不能直接用欧几里得距离来计算，所以我们需要用绝对值函数来计算dx和dy的绝对值
				// 在这道题里面mc火把萤石范围也是这个火把像是一个菱形模样然后这个观察到它的那个周围范围就是曼哈顿距离小于等于2的点，所以我们需要用绝对值函数来计算dx和dy的绝对值，然后再判断这个点是否在这
				//include<stdlib.h> is used for abs() function,这个是绝对值函数，abs(-5) = 5, abs(5) = 5
				if (s <= 2 && s >= -2)
				{
					nx = x + dx;
					ny = y + dy;
					if(nx>=1 && nx<=n && ny>=1 && ny<=n)
					{
						//这个就跟那个蛇形方阵一样防止数组越界，防止访问到数组外面的内存空间，造成程序崩溃
						// Do something
						arr[nx][ny] = 1;
					}
				}
			}

		}
	}
	//这个萤石是个正方形所以不用跟上面的火把一样只需要他在这个正方形里面就行了所以不用计算曼哈顿距离
		for (i = 1; i <= k; i++)
		{
			scanf("%d %d", &x, &y);
			for (dx = -2;dx <= 2;dx++)
			{
				for (dy = -2; dy <= 2; dy++)
				{
					nx = x + dx;
					ny = y + dy;
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
					{
						// Do something
						arr[nx][ny] = 1;
					}
				}

			}
		}
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j <= n;j++)
			{
				if (arr[i][j] == 0)
				{
					count++;
				}
			}
		}
	printf("%d", count);
	return 0;
}