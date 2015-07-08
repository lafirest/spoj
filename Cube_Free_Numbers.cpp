// 开始尝试使用树结构,但尝试几次后,发现简单的筛法即可了
#include <stdio.h>
#define LIMIT 1001000

int counts[LIMIT]; 

int main(void)
{
    int v, t, n;
    for(int i = 2; i <= 101; ++i)
    {
        int cube = i * i * i;
        if(cube >= LIMIT)
            break;
        
        int j = 2;
        int mcube = cube;
        while(mcube < LIMIT)
        {
            counts[mcube] = -1;
            mcube = j * cube;
            ++j;
        }
    }

    for(int i = 1, j = 1; i < LIMIT; ++i)
    {
        if(counts[i] == 0)
        {
            counts[i] = j;
            ++j;
        }
    }

    scanf("%d", &t);
    for(int i = 1; i <= t; ++i)
    {
        scanf("%d", &v);
        if(counts[v] == -1)
            printf("Case %d: Not Cube Free\n", i);
        else 
            printf("Case %d: %d\n", i, counts[v]);
    }

    return 0;
}


