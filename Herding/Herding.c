// 这个是github上的一个代码,这种实现比之前的两个实现都更好
// 版本一需要引入额外的空间(记录走过的路径),版本二需要引入额外的时间(两次搜索)
// 版本一和二都是因为在染色前无法确定该次应该染什么色,所以需要引入额外的时间和空间来辅助
// 这个版本的实现则是在颜色分配上进行的处理,每次搜索一个未染色节点时,都分配一个新的颜色(临时的),
// 然后直接进行染色,和版本一和二一样,在没有越界的情况下,搜索将会在一个有染色的节点处结束,
// 然后返回这个颜色,如果这个颜色比当前分别的颜色小,则说明当前搜索的路径和之前某个路径连通,
// 染色不正式分配,否则就新分配
#include <stdio.h>
#define MAX 1000
char grid[MAX][MAX+1];
int trap[MAX][MAX], count, color;

void floodfill(int i, int j, int n, int m)
{
    if(i >= 0 && j >= 0 && i < n && j < m)
    {
        if(trap[i][j])
        {
            // 返回结束时遇到的颜色
            count = trap[i][j];
            return;
        }

        // 给当前节点填充颜色
        trap[i][j] = count;

        if(grid[i][j]=='W') 
            floodfill(i, j-1, n, m);
        else if(grid[i][j]=='E') 
            floodfill(i, j+1, n, m);
        else if(grid[i][j]=='N') 
            floodfill(i-1, j, n, m);
        else if(grid[i][j]=='S') 
            floodfill(i+1, j, n, m);

        // 给当前节点从新染色(如果结束时遇到了之前的某个颜色,则所有节点重新染色,和之前的颜色连通
        // 如果不是则,实际上没有什么改变)
        // 这个和版本1实际上一样,版本1自己维护了一个访问链表,结束时染色,这个用递归,由系统维护一个
        // 访问链表,然后递归返回时重新染一次色
        trap[i][j] = count;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) 
        scanf("%s", grid[i]);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!trap[i][j])
            {
                count = color + 1;
                floodfill(i, j, n, m);
                if(count > color) 
                    ++color;
            }

    printf("%d\n", color);
    return 0;
}
