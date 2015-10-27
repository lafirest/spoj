// 这里是WA,因为m的范围没有指定,哈哈
#include <stdio.h>
#include <memory.h>

#define MAPMAX 200100
#define ARRMAX 100100
#define OFFSET 100000

int array[ARRMAX];
char map[MAPMAX];

int fastio(void)
{
    int n = 0;
    int s = 1;

    char p = getchar();

    // 读取空白等
    while((p < '-' || p > '9') && p != EOF)
        p = getchar( );

    // 读取符号位
    if(p == '-')
    {
        s = -1;
        p = getchar( );
    }

    // 生成数字
    while(p >= '0' && p <= '9')
    {
        // n = n * 10 + (p - '0')
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar( );
    }

    return n * s;
}

int main(void)
{
    int t = fastio();

    while(t--)
    {
        int n = fastio();
        int m = fastio();
        memset(map, 0, sizeof(char) * n);

        for(int i = 0; i < n; ++i)
        {
            int temp = fastio();
            array[i] = temp;
            map[temp + OFFSET] = 1;       
        }

        int count = 0;

        for(int i = 0; i < n; ++i)
        {
            int cur = array[i];
            int mappos = cur + OFFSET;
            if(!map[mappos])
                continue;

            int need = m - cur;
            int needpos = need + OFFSET;
            if(map[needpos])
            {
                ++count;
                map[needpos] = 0;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
