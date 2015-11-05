// ad-hoc 没啥好说的
#include <stdio.h>

#define MAX 10
#define INF 0x7FFFFFFF

char state[MAX][MAX];
char s1[MAX];

int read(void)
{
    int n = 0;
    char p = getchar();

    while(p < '0')
        p = getchar();

    while(p >= '0')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n;
}

int main(void)
{
    int t = read();
    for(int c = 1; c <= t; ++c)
    {
        int n = read();
        int p = read();
        int min = INF;
        int max = 0;

        for(int i = 0; i < n; ++i)
        {
            int solve = 0;
            for(int j = 0; j < p; ++j)
            {
                int s = read();
                if(s == 1)
                {
                    s1[j] = 1;
                    ++solve;
                }
            }

            if(solve < min)
                min = solve;

            if(solve > max)
                max = solve;
        }

        int s1v = 0;
        for(int i = 0; i < p; ++i)
        {
            s1v += s1[i];
            s1[i] = 0;
        }

        int r = 0;
        if(s1v == p)
            r = 4;

        if(min == 1)
            r |= 2; 

        if(max < p)
            r |= 1;
        
        printf("Case %d: %d\n", c, r);
    }

    return 0;
}
