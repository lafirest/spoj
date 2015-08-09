#include<stdio.h>

int
main(void)
{
    char buffer[255] = "";
    buffer[254] = 0;
    char manku[5] = "manku";
    int n, pos;
    long long int x, mod;
    
    scanf("%d", &n);
    while(n--)
    {
        pos = 253; //这里只能从253开始,254要用作NULL,因为这个原因浪费一次ac
        scanf("%lld", &x);
        while(x)
        {
           mod = x % 5;
           if (mod == 0)
           {
              buffer[pos] = 'u';
              --pos;
              x = x / 5;
              --x;
           }
           else
           {
              buffer[pos] = manku[mod - 1];
              --pos;
              x = x / 5;
           }
        }

        printf("%s\n", buffer + pos + 1);
    }
    return 0;
}
