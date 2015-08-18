// 求棋局有效性的题目,但是关于什么是'有效的最终状态'定义的很模糊,比如有两个属于同一个玩家
// 的获胜情况,不可能出现在井字游戏里面,但在这儿却是有效的...
#include <stdio.h>

// 为了方便,输入的字符串没有被切割成3x3数组.这里存的是所有的获胜情况
int point[][3] =
{
    // 水平
    {1,2,3},
    {4,5,6},
    {7,8,9},

    // 垂直
    {1,4,7},
    {2,5,8},
    {3,6,9},

    // 对角线
    {1,5,9},
    {3,5,7}
};

int 
main(void)
{
    char buffer[16];
    while(1)
    {
        scanf("%s", buffer + 1); 
        if(buffer[1] == 'e')
            break;

        int nx = 0;
        int no = 0;
        int wx = 0;
        int wo = 0;

        // 统计X和O的个数,注意输入里面还包括'.'
        for(int i = 1; i <= 9; ++i)
        {
            if(buffer[i] == 'X')
                ++nx;
            else if(buffer[i] == 'O')
                ++no;
        }

        // 遍历所有获胜的方法,统计各自的获胜次数
        for(int i = 0; i < 8; ++i)
        {
            int* array = point[i];
            int p1 = array[0];
            int p2 = array[1];
            int p3 = array[2];
            char mid = buffer[p2];
            if(buffer[p1] == mid && mid == buffer[p3])
            {
                // 注意有可能是三个'.'连成一条线了
                // 这个循环可以优化,当wx&&wo时,必然是无效的了,
                // 此时可以直接退出循环
                if(mid == 'X')
                    ++wx;
                else if (mid == 'O')
                    ++wo;
            }
        }

        int check = 1;

        // x先手,所以no不可能比nx大
        if(no > nx)
            check = 0;

        // x先手,所以最多只会多一个
        if(nx > no + 1)
            check = 0;

        if(check)
        {
            // 不可能两个同时获胜
            if(wx && wo)
                check = 0;
            else if(wx)
                check = nx == no + 1; // 先手获胜,则必然多一个
            else if(wo)
                check = nx == no;     // 后手获胜,则两个一样多
            else if(no + nx != 9)     // 平局,两边应该占满了所有格子
                check = 0;
        }

        if(check)
            printf("valid\n");
        else
            printf("invalid\n");
    }

    return 0;
}
