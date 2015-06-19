// 遍历字符串统计每个字符的频率
// 遍历频率统计的数组输出字符
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX 1001
#define min(a,b) (a) < (b) ? (a) : (b)

void set(char *str, short *arr)
{
    while(*str)
    {
        ++arr[*str-97];
        ++str;
    }
}

int 
main(void)
{
    short alphaA[26] = {0};
    short alphaB[26] = {0};
    char str[MAX] = {0};
    int i, j;
    while(scanf("%s", str) != EOF)
    {
        memset(alphaA, 0, 26 * sizeof(short));
        memset(alphaB, 0, 26 * sizeof(short));

        set(str, alphaA);

        scanf("%s", str);

        set(str, alphaB);

        for( i = 0; i < 26; i++)
        {
            if(alphaA[i] && alphaB[i])
            {
                j = min(alphaA[i], alphaB[i]);
                for( ; j > 0; --j)
                    printf("%c", i + 97);
            }
        }
        printf("\n");
    } 
}
