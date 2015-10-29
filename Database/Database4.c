// 和上个版本唯一的区别就是,把二维数组改成了一维数组,减少了寻址时间
// 0.04s
#include <stdio.h>

#define MAXI 10001
#define MAXC 10000

char map[MAXI * MAXC];
int color = 1;

int fastio(void)
{
    int n = 0;
    int s = 1;

    char p = getchar();

    // 读取空白等
    while(p < '0')
        p = getchar( );

    // 生成数字
    while(p >= '0') 
    {
        // n = n * 10 + (p - '0')
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar( );
    }

    return n * s;
}

void fastio_v(void)
{
    char p = getchar();

    // 读取空白等
    while(p < '0')
        p = getchar( );

    // 读取数字
    while(p >= '0') 
        p = getchar( );
}

int main(void)
{
    int t = fastio();

    for(int i = 1; i <= t; ++i)
    {
        int n = fastio();
        int r = fastio();

        while(r--)
        {
            int si = fastio();
            int c = fastio();
            int pos = si * MAXI + c;
            if(map[pos] != color)
                map[pos] = color;
            else
            {
                while(r--)
                {
                    fastio_v();
                    fastio_v();
                }

                printf("Scenario #%d: impossible\n", i);
                goto end;
            }
        }

        printf("Scenario #%d: possible\n", i);

        end:
            ++color;
    }

    return 0;
}
