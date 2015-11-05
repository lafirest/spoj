// 按照题目意思用递归实现的版本,会tle
#include <stdio.h>

#define MAX 1000
char strs[MAX];
char strt[MAX];
int slen;
int tlen;

int read(char *str, int *len)
{
    char p = getchar();
    int n = 0;
    while(p < '#')
        p = getchar();

    if(p == '#')
        return 0;

    while(p > '#')
    {
        *str = p;
        ++str;
        p = getchar();
        ++n;
    }

    *len = n;

    return 1;
}

int sum(int s, int e, int value)
{
    if(s >= e)
        return 0;
    else
        return (e - s) * value;
}

int calc(int i, int j)
{
    if(i >= slen)
        return sum(j, tlen, 30);
    else if(j >= tlen)
        return sum(i, slen, 15);
    else if(strs[i] == strt[j])
        return calc(i + 1, j + 1);
    else
    {
        int x = 15 + calc(i + 1, j);
        int y = 30 + calc(i, j + 1);
        return x > y ? y : x;
    }
}

int main(void)
{
    while(1)
    {
        slen = 0;
        tlen = 0;
        if(!read(strs, &slen))
            break;

        read(strt, &tlen);

        printf("%d\n", calc(0,0));
    }

    return 0;
}
