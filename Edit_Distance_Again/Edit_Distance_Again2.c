// 这个解法是github上看到的,思路很简单,计算将原序列变成小大小大...和变成
// 大小大小...这两种形式需要的次数,然后选用次数较小的那个即可
#include <stdio.h>

char state[255];
char buffer[1001];

int main(void)
{
    int i, sf, ss;
    char *str;
    char c, cs;
    for(i = 'A'; i <= 'Z'; ++i)
        state[i] = 1;

    while(scanf("%s", buffer) != EOF)
    {
        str = buffer; 
        i = 0;
        sf = 0;
        ss = 0;
        while((c = *str))
        {
            cs = state[c];
            if(i & 1)
            {
                sf += cs == 1 ? 1 : 0;
                ss += cs == 1 ? 0 : 1;
            }
            else
            {
                ss += cs == 1 ? 1 : 0;
                sf += cs == 1 ? 0 : 1;
            }

            ++i;
            ++str;
        }

        printf("%d\n", sf < ss ? sf : ss);
    }

    return 0;
}
