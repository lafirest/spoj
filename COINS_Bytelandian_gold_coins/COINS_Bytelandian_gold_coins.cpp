// 这道题目使用递归求解,因为n的值较大,所以需要进行记忆化
#include <iostream>  
#include <cstdlib>  
#include <cstdio>
using namespace std;  

#define MEMOSIZE 1000000  
unsigned memo[MEMOSIZE];  
unsigned maxprofit(unsigned n) 
{  
    unsigned s;  
    if ((n<MEMOSIZE) && memo[n]) 
        return memo[n] - 1;  
    s = maxprofit(n / 2) + maxprofit(n / 3) + maxprofit(n / 4);  
    s = (s > n) ? s : n;  
    if(n<MEMOSIZE) 
        memo[n]=s + 1;  
    return s;  
}  

int main(void) 
{  
    unsigned n;  
    // 这里n+1是为了使memo[0] != 0,否则上面的memo[0]将会判断不过,
    // 程序会陷入无限递归中
    for(n = 0; n < 12; ++n) 
        memo[n]= n + 1;  
    while(scanf("%u", &n) == 1) 
        cout << maxprofit(n) << endl;  
    return 0;
}   
