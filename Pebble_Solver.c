#include <stdio.h>

char buffer[1024 * 1024];

int main(void)
{
    int n = 0, v, flag;
    char *str;
    char c;
    while(scanf("%s", buffer) != EOF)
    {
        ++n;
        v = 0;
        flag = 0;
        str = buffer;
        while((c=*str))
        {
            if((c - 48) ^ flag)
            {
                ++v;
                flag = !flag;
            }

            ++str;
        }

        printf("Game #%d: %d\n", n, v);
    }
    return 0;
}
