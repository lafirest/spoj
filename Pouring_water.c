//http://rchardx.is-programmer.com/posts/16699.html
//这道题目是看上面的博客的答案的.我的思路离正确答案
//差三步
//1:是判断无解,我的条件是都小于c,或c不是差的倍数
//正确应该判断的是两者的gcd,如11 5 10,差是6,10不是其
//倍数,但两者的gcd是1,能碾转得到1,然后堆积成10
//2:模拟过程分析的不全面,和实际操作过程不一致,应该一步步
//的来模拟,ac不足则加满,bc满了则减,出错的是下面这点,都
//不为0时,以ac(满)和b剩余的空间两则小的部分进行空间交换
//而我的处理方式是先比较a、b的大小,然后在传入.
//3:这里的原因就是因为2比较了a、b的大小导致的,正确的做法
//是a、b分别当作第一个操作的对象进行模拟,然后两次模拟的最小值就是结果了
#include <stdio.h>

#define min(a,b) (a) < (b) ? (a) : (b)

int gcd(int a, int b)
{
    if(!b)
        return a;
    
    return gcd(b, a%b);
}

int search(int a, int b, int c)
{
    int ac = 0, bc = 0, times = 0, diff;
    if(a < c && b < c)
        return -1;
    else if(c % gcd(a,b))
        return -1;
    else 
        while(1)
        {
            if(ac == c || bc == c)
                break;
            
            if(bc == b)
                bc = 0;
            else if(ac == 0)
                ac = a;
            else 
            {
                diff = min(b - bc, ac);
                ac -= diff;
                bc += diff;
            }
            ++times;
        }

    return times;
}

int main(void)
{
    int n,a,b,c,t;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", min(search(a, b, c), search(b, a, c)));
    }
    return 0;
}
