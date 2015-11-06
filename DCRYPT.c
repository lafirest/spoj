// 不怎么好的一道题目
#include <stdio.h>

int key;

void deal(int invertedp)
{
    char p = getchar();
    while(p <= ' ')
        p = getchar();

    while(p > ' ')
    {
        if(p == '.')
            putchar(' ');
        else
        {
            int sub = 0;
            int add = 0;
            if(p <= 'Z')
            {
                sub = 64;
                add = 96;
            }
            else 
            {
                sub = 96;
                add = 64;
            }

            char s = p - sub;
            s += key;
            s %= 26;
            if(s == 0)
                s = 26;

            if(!invertedp)
                add = sub; 

            putchar(s + add);
        }

        p = getchar();
    }
}


int main(void)
{
    int t; 
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &key);
        if(key <= 25)
            deal(0);
        else
            deal(1);

        putchar('\n');
    }

    return 0;
}
