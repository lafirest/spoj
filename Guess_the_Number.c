// 求出所有Y位的最小公倍数,如果有解,这个就是最小值.
// 然后用这个最小公倍数从小的N开始,判断是否能进行正除,
// 如果有一个N能被整除,则不存在这样的一个数
#include <stdio.h>

char buffer[21];
int narr[21];
int pos;

long long int gcd(long long int a, long long int b)
{
    if(!b)
        return a;

    return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    char *str;
    long long int vlcm;
    int i, has;
    char c;
    while(1)
    {
        gets(buffer);
        if(*buffer == '*')
            break;

        pos = 0;
        str = buffer;
        vlcm = 1;
        i = 1;
        while((c = *str))
        {
            if(c == 'Y')
                vlcm = lcm(i, vlcm);
            else
            {
                narr[pos] = i;
                ++pos;
            }
            
            ++str; 
            ++i;
        }

        has = 1;
        for(i = 0; i < pos; ++i)
            if(vlcm % narr[i] == 0)
            {
                has = 0;
                printf("-1\n");
                break;
            }

        if(has)
            printf("%d\n", vlcm);
    }
    return 0;
}

