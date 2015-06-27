#include <stdio.h>
#include <string.h>

char arr[255] ={0};

int main(void)
{
    int n,i,j,falg;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s", arr);
        falg = 1;
        j = strlen(arr) - 1;
        for(i = 0; i < j && falg; ++i, --j)
            if(arr[i] != arr[j])
                falg = 0;

        if(falg) 
           puts("YES");
        else
           puts("NO");
    }
    return 0;
}
