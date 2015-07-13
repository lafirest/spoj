// 这里这样做是因为找了几个规律,发现三个三个来处理就能得到最小次数了
// 结果WA了.
#include <stdio.h>

char state[255];
char buffer[1001];

int main(void)
{
    int i, v;
    char *str;
    char c, ls, cs, ns;
    for(i = 'A'; i <= 'Z'; ++i)
        state[i] = 1;

    while(scanf("%s", buffer) != EOF)
    {
        str = buffer; 
        v = 0;
        while((c = *str))
        {
            ls = state[c];
            if(!(*(str+1)))
                break;
            cs = state[*(str+1)];
            if(!(*(str+2)))
            {
                v += ls == cs;
                break;
            }
            ns = state[*(str+2)];
            if(ls != cs && cs != ns)
                str += 2;
            else if(ls != cs && cs == ns)
            {
                ++v;
                if(ns)
                    *(str+2) = 'a';
                else 
                    *(str+2) = 'A';

                str +=2;
            }
            else 
            {
                ++v;
                str += 2;
            }
        }

        printf("%d\n", v);
    }

    return 0;
}
