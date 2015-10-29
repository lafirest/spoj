#include <stdio.h>  
#include <string.h>  
char c[1005];  
int f[12], sum;  
int check()  
{  
    if(sum%3==1&&f[1]==0&&f[4]==0&&f[7]==0&&(f[2]+f[5]+f[8]<2))  
        return 0;  
    if(sum%3==2&&f[2]==0&&f[5]==0&&f[8]==0&&(f[1]+f[4]+f[7]<2))  
        return 0;  
    return 1;  
}  
void solve()  
{  
    if(sum%3==1)  
    {  
        if(f[1]) --f[1];  
        else if(f[4]) --f[4];  
        else if(f[7]) --f[7];  
        else if(f[2]>=2) f[2]-=2;  
        else if(f[2]&&f[5]) { --f[2]; --f[5]; }  
        else if(f[5]>=2) f[5]-=2;  
        else if(f[2]&&f[8]) { --f[2]; --f[8]; }  
        else if(f[5]&&f[8]) { --f[5]; --f[8]; }  
        else if(f[8]>=2) f[8]-=2;  
    }  
    else if(sum%3==2)  
    {  
        if(f[2]) --f[2];  
        else if(f[5]) --f[5];  
        else if(f[8]) --f[8];  
        else if(f[1]>=2) f[1]-=2;  
        else if(f[1]&&f[4]) { --f[1]; --f[4]; }  
        else if(f[4]>=2) f[4]-=2;  
        else if(f[1]&&f[7]) { --f[1]; --f[7]; }  
        else if(f[4]&&f[7]) { --f[4]; --f[7]; }  
        else if(f[7]>=2) f[7]-=2;  
    }  
}  
int main ()  
{  
    int t, last;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%s",c);  
        int len = strlen(c);  
        memset(f,0,sizeof(f));  
        for(int i = 0; i < len; ++i)  
            ++f[c[i]-'0'];  
        if(f[0]==0&&f[5]==0) { printf("impossible\n"); continue; }  
        if(f[0])  
        {  
            --f[0];  
            last = 0;  
        }  
        else  
        {  
            --f[5];  
            last = 5;  
        }  
        sum = last;  
        for(int i = 1; i <= 9; ++i) sum+=f[i]*i;  
        if(check()==0) { printf("impossible\n"); continue; }  
        else solve();  
        for(int i = 9; i >= 0; --i)
        {
            for(int j = 0; j < f[i]; ++j)  
                printf("%d",i); 
        }
        printf("%d\n",last);  
    }  
    return 0;  
}  
