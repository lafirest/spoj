// 注意输入格式的一道题目
#include <stdio.h>
#include <memory.h>

#define MB 1024 * 1024
int len[21];
int mlen[21];   //len和mlen都可以优化掉,mlen用一个max变量即可,后面就无须遍历数组了
char buffer[MB];
char map[256];

// 对一个字符串进行统计
void count(char *str)
{
    char c;
    char *next;
    int lc = 0; //当前的单词长度
    int ll = 0; //上一个单词的长度
    while((c =*str))
    {
        // next指向下一个字符
        next = str;
        ++next;

        // 有效则当前长度+1
        if(map[c])
            ++lc;
        else 
        {
            // 无效则给统计数组对应单词长度位+1
            ++len[lc];

            // 和该长度历史最大连续值进行比较
            if(len[lc] > mlen[lc]) 
                mlen[lc] = len[lc];

            // 1.这里没必要每次都判断,只在上一个连续片段结束时判断即可
            // 2.没必要用len数组,使用一个变量即可.每次进入这个分支时
            // 如果lc != ll且ll != 0,则变量len和max比较,然后len重置为1
            // 开始新的片段计数,否则len继续增长

            // 如果这次的单词长度和上次的单词长度不一样
            // 则上一次不在连续,将len数组对应位置置为0
            if(lc != ll)
                len[ll] = 0;

            ll = lc;
            lc = 0;

            // 题目说只有一个空格分隔,但实际上可能有很多个
            // 向后扫描直到遇到第一个有效字符
            while(*next)
            {
                if(map[*next])
                    break;
                else
                    ++next;
            }
        }
        str = next;
    }
}

int main(void)
{
    int i,n,m;
    scanf("%d", &n);
    scanf("\n");    // 读取换行符

    // 初始化映射表
    for(i = 0; i < 256; ++i)
    {
        // 题目说只有空格是分隔符,但实际上有很多其他分隔符，
        // 但有效范围只有a~z
        if(i < 'a' || i > 'z')
            map[i] = 0;
        else
            map[i] = 1;
    }

    while(n--)
    {
        m = 0;
        gets(buffer);
        memset(len, 0, 21 * sizeof(int));
        memset(mlen, 0, 21 * sizeof(int));
        count(buffer); 

        // 遍历获得最大的连续长度
        for(i = 1; i < 21; ++i)
            if(mlen[i] > m)
                m = mlen[i];

        printf("%d\n", m);
    }

}
