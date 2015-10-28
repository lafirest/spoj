// 这个是版本1,不能ac.版本2改用c++写,改变的只有io部分,但是版本2ac了...
// 很神奇.暂时不知道为什么.
//
// 这个题的本质就是字符频率统计,然后有一点就是E是字符的起点,所有A和E相距的距离
// 不是4,而是22,这个是个坑,其他没什么.
#include <stdio.h>

#define MAX 126
int counter[MAX];
char buffer[MAX];

int main(void)
{
    int t;
    char p;
    scanf("%d", &t);

    while(t--)
    {
        // 一直读取到第一个比空格大的字符(理论上只会是A-Z)
        // EOF \n \r \t这些可能出现的都会被过滤掉呀!!!
        do
        {
            p = getchar();
        }while(p <= ' ');

        // 一直读取到第一个比空格小的字符(理论上应该只有换行)
        // 我知道为什么不能ac了...输入里面的分隔符,不是空格,
        // 或者不止是空格,应该还有\t,坑
        // 但是下面改了,还是不能ac...
        int pos = 0;
        while(p != '\n' && p != '\r')
        {
            ++counter[p];
            buffer[pos] = p;
            p = getchar();
            ++pos;
        }
        buffer[pos] = '\0';

        // 统计字符频率
        int max = 0;
        int index = 0;
        for(int i = 'A'; i <= 'Z'; ++i)
        {
            int ci = counter[i];
            if(ci > max)
            {
                max = ci;
                index = i;
            }
        }

        // 合法性检测
        int check = 0;
        for(int i = 'A'; i <= 'Z'; ++i)
        {
            if(counter[i] == max)
            {
                ++check;
                if(check == 2)
                    break;
            }
        }

        if(check > 1)
            puts("NOT POSSIBLE");
        else
        {
            // 计算距离修正字符串
            int dis = index - 'E';
            if(dis < 0)
                dis = 26 + dis;

            for(int i = 0; i < pos; ++i)
            {
                char ci = buffer[i];
                if(ci <= ' ')
                    continue;

                char cir = ci - dis;
                if(cir < 'A')
                    cir += 26;

                buffer[i] = cir;
            }

            printf("%d ", dis);
            puts(buffer);
        }

        for(int i = 'A'; i <= 'Z'; ++i)
            counter[i] = 0;
    }

    return 0;
}
