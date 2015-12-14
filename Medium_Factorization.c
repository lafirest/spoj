#include <stdio.h>

#define max 10000010
#define seq 3163

int arr[max];

int main(void)
{
    for(int i = 2; i <= seq; ++i)
    {
        if(arr[i])
            continue;

        arr[i] = i;
        for(int j = i * i; j < max; j += i)
            if(!arr[j])
                arr[j] = i;
    }

    int n;
    while(1)
    {
        if(EOF == scanf("%d", &n) )
            break;

        putchar('1');

        while(n > 1)
        {
            int f = arr[n];
            if(f == 0)
            {
                f = n;
                arr[n] = n;
            }

            printf(" x %d", f);
            n /= f;
        }

        putchar('\n');
    }

    return 0;
}
