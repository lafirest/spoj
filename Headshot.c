//这道题目不会做,然后看到了题目,还是不会做,之后查了下是全概率公式的应用
//概率论的东西都忘记了,既然答案都看了好几遍了,就可耻的提交刷下分...
//https://github.com/cacophonix/SPOJ/blob/master/HEADSHOT.cpp
//全概率公式:http://baike.baidu.com/link?url=J3Nqrubji8HUoOFKzdiUP9biF5Io-NBoZHQLGfPmH_qtceYS8zD6yczkuSG6bA2mWcBjfJFlnwISlNJRgwhPYa
#include <stdio.h>
#include <math.h>

int 
main(void) 
{
    char round[110];
    double total, zero, ones, cnt;
    scanf("%s", round);
    total = zero = ones = cnt = 0;
    for(int i = 0; round[i]; ++i, ++cnt) 
    {
        if(round[i]=='0') 
        {
            total++;
            if(round[i+1]) 
            {
                zero += round[i+1]=='0';
                ones += round[i+1]=='1';
            }
            else 
            {
                zero += round[0]=='0';
                ones += round[0]=='1';
            }
        }
    }

    if(fabs(zero/(zero+ones) - total / cnt) < 1e-10) 
        puts("EQUAL");
    else if(zero/(zero+ones) > total / cnt) 
        puts("SHOOT");
    else 
        puts("ROTATE");

    return 0;
}
