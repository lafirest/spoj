// 不好归纳,算集合内连续数链表的个数吧
// 刚开始读完后觉得不太好做,想了会儿发现蛮简单的:
// 读入一个数,如果这个数左边有链表了,则这个数并入左边的链表,g-1
// 如果这个数右边有链表了,则右边的链表并入这个数,g-1
// 左边有链表、右边有链表、两边都有、两边都没有,则四种情况下加上上面的操作
// 最后必然会多出一个链表,g+1
#include <stdio.h>

#define MAX 30000
char array[MAX];

int 
main(void)
{
    int n;
    int g = 0;
    scanf("%d", &n);

    while(n--)
    {
        int q;
        scanf("%d", &q);
        array[q] = 1;

        if(array[q-1])
            --g;

        if(array[q+1])
            --g;

        ++g;

        printf("%d\n", g);
    }

    printf("Justice\n");

    return 0;
}


