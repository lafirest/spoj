// 具体算法见http://www.cnblogs.com/PrimoPrimo/p/3307126.html
// 一直搞不懂为什么我的这个版本不能ac,而它的那个能ac
// 版本2就是blog上的代码.算法是一样的，不知道是哪个地方出了错
#include <stdio.h>

char counter[10];

int read(void)
{
    int n = 0;
    char p = getchar();
    while(p < '0')
        p = getchar();

    while(p >= '0')
    {
        ++n;
        ++counter[p - '0'];
        p = getchar();
    }

    return n;
}

int fixup_mod1(void)
{
    if(counter[1])
        --counter[1];
    else if(counter[4])
        --counter[4];
    else if(counter[7])
        --counter[7];
    else if(counter[2] >= 2)
        counter[2] -= 2;
    else if(counter[2] && counter[5])
    {
        --counter[2];
        --counter[5];
    }
    else if(counter[5] >= 2)
        counter[5] -= 2;
    else if(counter[2] && counter[8])
    {
        --counter[2];
        --counter[8];
    }
    else if(counter[5] && counter[8])
    {
        --counter[5];
        --counter[8];
    }
    else if(counter[8] >= 2)
        counter[8] -= 2;
    else
        return 1;

    return 0;
}

int fixup_mod2(void)
{
    if(counter[2])
        --counter[2];
    else if(counter[5])
        --counter[5];
    else if(counter[8])
        --counter[8];
    else if(counter[1] >= 2)
        counter[1] -= 2;
    else if(counter[1] && counter[4])
    {
        --counter[1];
        --counter[4];
    }
    else if(counter[4] >= 2)
        counter[4] -= 2;
    else if(counter[1] && counter[7])
    {
        --counter[1];
        --counter[7];
    }
    else if(counter[4] && counter[7])
    {
        --counter[4];
        --counter[7];
    }
    else if(counter[7] >= 2)
        counter[7] -= 2;
    else
        return 1;

    return 0;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int len = read();
        if(len < 2)
            goto im;

        if(counter[0] == 0 && counter[5] == 0)
            goto im;

        char last = 0;
        int flag = 0;
        if(counter[0])
        {
            --counter[0];
            last = 0;
        }
        else
        {
            --counter[5];
            last = 5;
        }

        int sum = last;
        for(int i = 0; i < 10; ++i)
            sum += counter[i] * i;

        int mod = sum % 3;
        switch(mod)
        {
            case 0:
                goto display;
            case 1:
                if(fixup_mod1())
                    goto im;
                break;
            case 2:
                if(fixup_mod2())
                    goto im;
                break;
        }

display:
        for(int i = 9; i >= 0; --i)
        {
            char p = i + '0';
            while(counter[i]--)
                putchar(p);
        }
        putchar(last + '0');
        putchar('\n');
        goto end;

im:
        puts("impossible");

end:
        for(int i = 0; i < 10; ++i)
            counter[i] = 0;
    }

    return 0;
}
