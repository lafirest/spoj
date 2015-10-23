#include <stdio.h>
// 这里的做法简单明了,求出当前的节点数n能满到第几个.然后累计
// 这个后面的值就可以了.
// 这段inp代码来自githup,算是fastio了.版本3用scanf来读取,速度
// 满了4倍
int 
inp( )
{
    int n = 0 , s = 1 ;
    // 读取符号位
    char p = getchar( ) ;
    if( p == '-' )
        s = -1 ;

    // 读取空白等
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-' )
        p = getchar( ) ;

    // 读取符号位
    if( p == '-' )
        s = -1 , p = getchar( ) ;

    // 生成数字
    while( p >= '0' && p <= '9' )
    {
        // n = n * 10 + (p - '0')
        n = ( n << 3 ) + ( n << 1 ) + ( p - '0' ) ;
        p = getchar( ) ;
    }

    return n * s ;
}

int 
main(void)
{
    while(1)
    {
        int n = inp();
        if(!n)
            break;

        int m = 0;
        if(n & 1)
            m = (n + 1) / 2;
        else
            m = n / 2;

        int s = n - m;

        int i = 1;
        for(; i <= s; ++i)
            inp();

        int sum = 0;
        for(; i <= n; ++i)
        {
            sum += inp();
        }

        printf("%d\n", sum);
    }

    return 0;
}
