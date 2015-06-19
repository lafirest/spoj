#include <stdio.h>
#include <string.h>

// 高精度除法,将返回值改为余数,就成了高精度求余了
// http://www.cnblogs.com/lsx54321/archive/2012/07/24/2606334.html
int mod(char *src, int n)
{
    int len = strlen(src),i,k,t=0,s=0;
    char dest[255];
    //商是否有了第一个有效位，防止商首部一直出现    
    int flag = 1;    
    for(i=0,k=0; i<len; ++i)
    {
        // 余数
        t = s * 10 + (src[i] - 48);    
        if(t / n > 0 || t==0)     //余数为要修改商  
        {
            dest[k++] = t/n + 48;
            s = t%n;
            flag = 0;
        }
        //不够除，修改余数
        else                    
        {
            s = t;
            //商已经有有效位了，补零
            if(!flag)            
                dest[k++] = '0';
        }
    }

    return t;
}

// 欧几里德算法, 源码大小限制没有使用binary GCD algorithm
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else 
        return gcd(b, a%b);
}

int main (void)
{
    int t,a;
    char b[255] = "";
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %s", &a, b);
        if(!a)
            printf("%s\n", b);
        else if (b[0] == '0') 
            printf("%d\n", a);
        else 
            printf("%d\n", gcd(a, mod(b, a)));
    }
}
