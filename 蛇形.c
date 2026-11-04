#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int arr[10][10] = { 0 };
    //还有这里的问题我应该先初始化一下因为不初始化接下来的数值都是垃圾值
    int n;
    int i, nx, ny, j;
    int x = 1;
    int y = 1;
    int d = 0;
    scanf("%d", &n);
    arr[1][1] = 1;
    for (i = 2;i <= n * n;i++)
    {
        if (d == 0) { nx = x;ny = y + 1; }//这个是来将它的方向设置
        if (d == 1) { nx = x + 1;ny = y; }//我最开始的想法是什么是两层for嵌套但是这个是错的
         //应该是什么应该是先设置一个起始点然后从这个起始点一直向后遇到不行的地方就开始将它转向
        if (d == 2) { nx = x;ny = y - 1; }
        if (d == 3) { nx = x - 1;ny = y; }

        //还有就是代码都是人写出来的加油！！
        if (nx<1 || nx>n || ny<1 || ny>n || arr[nx][ny] != 0)
        {
            d = (d + 1) % 4;
            //这里为什么要再来我还没学会等一下我学习一下
             //额我大概是知道了因为这个如果说这个判断是错误的没有转向这个i仍然会i++导致到了比方说5吧emm它就会跳过直接就是0然后到了下一个就是6了
            if (d == 0) { nx = x;ny = y + 1; }
            if (d == 1) { nx = x + 1;ny = y; }
            if (d == 2) { nx = x;ny = y - 1; }
            if (d == 3) { nx = x - 1;ny = y; }
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