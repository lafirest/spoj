//1和2算法一样,2是优化版，所以注释在2里面
#include <stdio.h>
#include <string.h>

char buffer[100001];

int 
main(void)
{
    while(1)
    {
        if(EOF == scanf("%s", buffer))
            break;

        int end = strlen(buffer) -1;
        int i = 0;
        int j = end;
        int si = i;
        int isp = 1;
        while(i <= j)
        {
            if(buffer[i] == buffer[j])
            {
                ++i;
                --j;
            }
            else
            {
                isp = 0;
                if(j == end)
                    ++i;
                else
                {
                    j = end;
                    i = si + 1;
                }

                si = i;
            }
        }

        printf("%s",buffer);
        if(!isp)
        {
            --si;
            for(; si >= 0; --si)
            {
                putchar(buffer[si]);
            }
        }
        printf("\n");
    }

    return 0;
}

