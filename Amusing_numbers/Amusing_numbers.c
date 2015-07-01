// 这是一个等比数列,根据输入的数算出其长度和相对于基数的偏移量
// 当数位为1(2^1)时,5出现1次,然后是6,当位置为2时时5出现2次,然后6出现
// 两次(5和6出现的次数和是2^i,前2^(i-1)次为5,后面一半是6).所以某一位为5或则6为,
// k = 偏移量 % 2 ^ i,k 小于等于1/2 2^1即为5否则就是6
#include <stdio.h>
#include <math.h>

// sn = 2^(n+1) - 2
void len(long long num, long long *pos, long long *len)
{
    long sn, n;
    double value = num + 2;
    // 这里不应该是sqrt而应该是log(value, 2)
    // 这里是开始导致超时的原因
    value = log(value) / log(2);
    n = value - 1;
    sn = pow(2, 1+n) - 2;
    if(sn < num)    
        ++n;
    *pos = num - pow(2, n) + 2;
    *len = n;
}

int main(void)
{
    int i,n;
    long long t, p, an, k, l, half;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lld", &t);
        len(t, &p, &l);
        for(i=l; i>=1; --i)
        {
            an = pow(2,i);
            half = an >> 1;
            k = p % an;
            while(p >= an)
                p -= an;
                
            if(!k)
                k = an;

            if(k <= half)
                putchar('5');
            else
                putchar('6');
        }

        printf("\n");
    }
    return 0;
}
