//http://blog.csdn.net/wdcjdtc/article/details/39718857
#include"cstdlib"  
#include"cstdio"  
#include"cstring"  
#include"cmath"  
#include"queue"  
#include"algorithm"  
#include"iostream"  
using namespace std;  
#define ll long long  
ll bit[66];  
int main()  
{  
    bit[1]=0;  
    for(int i=2;i<=51;i++) bit[i]=(1LL<<i)-2; //注意加LL  
    int t;  
    cin>>t;  
    while(t--)  
    {  
        ll k;  
        int i;  
        scanf("%lld",&k);  
        for(i=51;i>=1;i--) if(bit[i]<k) break;  //确认几位数  
        ll tep=k-bit[i]-1;  //几位数的第几个  
        int num[66],cnt=0;  
        while(tep)  
        {  
            num[++cnt]=tep%2;  
            tep/=2;  
        }  
        for(int j=0;j<i-cnt;j++) printf("5");  //补上前面的0  
        for(int j=cnt;j>=1;j--)  
        {  
            if(num[j]) printf("6");  
            else printf("5");  
        }  
        puts("");  
    }  
    return 0;  
} 
