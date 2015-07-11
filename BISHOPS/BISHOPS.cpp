#include<cstdio>
#include<cstring>
char s[105];
int l,i,j,a[105];
int main()
{
    while(scanf("%s",&s)!=EOF)
    {
        l=strlen(s);
        memset(a,0,sizeof(a));
        if(l==1&&s[0]<'3')
            printf("%s\n",s);
        else
        {
            // 将字符串读入数组,"54321"变为{1,2,3,4,5}
            for (i = 0; i < l; ++i)
                a[l-i] = s[i] - 48; //这儿个位是1

            // 从个位开始,没一位等于 当前的值 * 2 + 前一位的进位(和10的商)
            // 上一位等于和10的余数(这样有进位和没进位都对)
            for (i = 1; i <= l; ++i)
            {
                a[i] = a[i] * 2 + a[i-1] / 10;
                a[i-1] %= 10;
            }

            // 结果是2n - 2,这里个位减去2
            a[1] -= 2;
            i=1;

            // 个位减去2后,如果小于0,向上借位
            while( a[i] < 0 )
            {
                a[i+1]--;   // 后一位借一位
                a[i]+=10;   // 当前位+10
                i++;        // 判断后一位借位后是否小于0
            }
            // 这里这个输出也不太好懂
            for ( i=l; i; --i)
                printf("%d",a[i]);
            printf("\n");
        }
        memset(s,0,sizeof(s));
    }    
    return 0;
}
