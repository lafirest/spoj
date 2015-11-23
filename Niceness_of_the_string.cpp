//题目很简单,但需要注意的地方比较多,修改了很多次,才ac
//1.没有必要对字符串进行倒置,倒置后不一样的字符串,倒置前也必然不一样
//2.注意整行都是空格的输入字符串,这个倒置了最开始的fast io写法tle
//3.注意连续空格倒置空字符串被写入pool中去
#include <cstdio>
#include <set>
#include <string>
#include <cstring>
using namespace std;

#define MAX 10010
char buffer[MAX];
char sub[MAX];
set<string> pool;
int len = 0;

void deal(void)
{
    int i = 0;
    int j = 0;

    // 去掉开头的空字符串
    while(buffer[i] <= ' ' && i < len)
        ++i;

    while(i < len)
    {
        // 使用空格断词
        if(buffer[i] <= ' ')
        {
            sub[j] = '\0';

            // j = 0，说明时连续空格,不处理
            if(j)
                pool.insert(sub);
            j = 0;
        }
        else
        {
            sub[j] = buffer[i];
            ++j;
        }

        ++i;
    }

    if(j)
    {
        sub[j] = '\0';
        pool.insert(sub);
    }
}

int main(void)
{
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        pool.clear();
        gets(buffer);
        len = strlen(buffer);
        deal();
        printf("%d\n", pool.size());
    }

    return 0;
}
