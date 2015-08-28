// 题目不难,兔子问题基本都能想到Fibonacci数列,主要是数据很大,只能做高精度运算了,
// 这个答案是从github上扒下来的.这样没意思...扒答案没意思
/*
http://en.wikipedia.org/wiki/Exponentiation_by_squaring
http://comeoncodeon.wordpress.com/2011/05/08/recurrence-relation-and-matrix-exponentiation/
http://zobayer.blogspot.in/2010/11/matrix-exponentiation.html
http://en.wikipedia.org/wiki/Fibonacci_number
http://mathworld.wolfram.com/FibonacciNumber.html
*/

#include <stdio.h>
#include <math.h>

#define bigint unsigned long long 

bigint MOD;

bigint 
matrix_exponentiation( bigint ex )
{
    bigint a[2][2] = { { 1 , 1 } , { 1 , 0 } } , temp[2][2] , i[2][2] = { { 1 , 0 } , { 0 , 1 } } ;

    if( ex == 0 )
        return 0 ;
    else if( ex == 1 )
        return 1 ;
    else
    {
        ex-- ;
        while( ex )
        {
            if( ex & 1 )
            {
                temp[0][0] = i[0][0] ;
                temp[0][1] = i[0][1] ;
                temp[1][0] = i[1][0] ;
                temp[1][1] = i[1][1] ;
                i[0][0] = ( ( temp[0][0] * a[0][0] ) + ( temp[0][1] * a[1][0] ) ) % MOD ;
                i[0][1] = ( ( temp[0][0] * a[0][1] ) + ( temp[0][1] * a[1][1] ) ) % MOD ;
                i[1][0] = ( ( temp[1][0] * a[0][0] ) + ( temp[1][1] * a[1][0] ) ) % MOD ;
                i[1][1] = ( ( temp[1][0] * a[0][1] ) + ( temp[1][1] * a[1][1] ) ) % MOD ;
            }
            temp[0][0] = a[0][0] ;
            temp[0][1] = a[0][1] ;
            temp[1][0] = a[1][0] ;
            temp[1][1] = a[1][1] ;
            a[0][0] = ( ( temp[0][0] * temp[0][0] ) + ( temp[0][1] * temp[1][0] ) ) % MOD ;
            a[0][1] = ( ( temp[0][0] * temp[0][1] ) + ( temp[0][1] * temp[1][1] ) ) % MOD ;
            a[1][0] = ( ( temp[1][0] * temp[0][0] ) + ( temp[1][1] * temp[1][0] ) ) % MOD ;
            a[1][1] = ( ( temp[1][0] * temp[0][1] ) + ( temp[1][1] * temp[1][1] ) ) % MOD ;
            ex >>= 1 ;
        }
    }
    return i[0][0] % MOD ;     
}

int main( )
{
    bigint t , n , m ;


    for( scanf("%llu",&t) ; t ; t-- )
    {
        scanf("%llu %llu",&n,&m) ;
        MOD = 1 << m ;
        printf("%llu\n",matrix_exponentiation( n + 1 )) ;
    }

    return 0 ;
} 
