// 水题,哈哈
#include <stdio.h>

#define MAX 21
#define make_pair(x,y) (x << 16 | y)
#define low(x) (x >> 16)
#define high(x) (x & 0xFFFF) 
int set[MAX];
int m, c;

void calc(int n, int p)
{
    if(n <= 0)
    {
        if(n == 0 && p == m)
            ++c;
            
        return;
    }

    if(p >= m)
        return;

    int x= set[p];
    int l = low(x);
    int h = high(x);
    ++p;

    for(int i = l; i <= h; ++i)
        calc(n - i, p);
}

int main(void)
{
    int n;
    while(1)
    {
        scanf("%d %d", &m, &n);
        if(0 == m && 0 == n)
            break;

        int l, h;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d %d", &l, &h);
            set[i] = make_pair(l, h);
        }

        c = 0;
        calc(n, 0);

        printf("%d\n", c);
    }
    
    return 0;
}
