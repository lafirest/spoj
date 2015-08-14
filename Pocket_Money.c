// http://blog.csdn.net/kkkwjx/article/details/9874837
// 典型的区间dp,而且做个许多次了,还是做错真是不应该!lisp版本的转移公式写成了
// 一维的,已经被删除了.
#include <stdio.h>  
#include <memory.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int dpmax[105][105]; 
int dpmin[105][105]; 
char op[105]; 

int main()  
{  
    int t;   
    scanf("%d", &t);   
    while(t--)  
    {  
        memset(dpmin, -1, sizeof(dpmin));   
        memset(dpmax, 0, sizeof(dpmax));   
        memset(op, 0, sizeof(op));   
        int n = 1; 
        int digit = 0;   

        while(scanf("%d%c", &digit, &op[n]))  
        {  
            dpmax[n][n] = dpmin[n][n] = digit;   
            if(op[n] == '\n') 
                break;   
            ++n;   
        }  

        for(int k = 1; k < n; ++k)  
            for(int i = 1; i + k <= n; ++i)  
                for(int j = i; j < i+k; ++j)  
                {  
                    int mx = 0;
                    int mn = 0;   
                    if(op[j] == '+')  
                    {  
                        mx = dpmax[i][j]+dpmax[j+1][i+k];   
                        mn = dpmin[i][j]+dpmin[j+1][i+k];   
                    }  
                    else  
                    {  
                        mx = dpmax[i][j]*dpmax[j+1][i+k];   
                        mn = dpmin[i][j]*dpmin[j+1][i+k];   
                    }  
                    dpmax[i][i+k] = max(dpmax[i][i+k],mx);   

                    if(dpmin[i][i+k] == -1) 
                        dpmin[i][i+k] = mn;   

                    dpmin[i][i+k] = min(dpmin[i][i+k],mn);   
                }  
        printf("%d %d\n",dpmax[1][n],dpmin[1][n]);   
    }  
    return 0;   
} 
