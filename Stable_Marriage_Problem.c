// 今天状态不佳,不想做题目,开始这道题目都理解错了,这道题目的要求是分配后不存在
// 有某个男的更爱某个女的胜过自己的妻子(这里分配的),且这个女的也更爱这个男的,而不是自己的丈夫
// 这里的做法是男的从列表开头往后面依次选择女的,如果这个女的没有分配则这两个分为一对.如果这个女的
// 已经被分配了,则从这个女的列表从头开始选择,如果已经分配给这个女的的男的在前面(更爱那个男的),
// 则当前这个男的,选择下一个女的;如果当前这个男的在前面,则这个女的和当前这个男的重新分为一对,被
// 抛弃的男的,从自己列表中这个女的的下一位开始搜索,重复上述步骤
#include <stdio.h>
#include <memory.h>

int women[510][510];    // 女的选择列表
int man[510][510];      // 男的选择列表
int w_marriage[510];    // 女的结婚对象
int m_marriage[510];    // 男的结婚对象
int n;              

void
find(int i, int j)
{
    for( ; j <= n; ++j)
    {
        int w = man[i][j];
        if(!w_marriage[w])
        {
            w_marriage[w] = i;
            m_marriage[i] = w;
            return;
        }
        else
        {
            int anti = w_marriage[w];
            for(int z = 1; z <= n; ++z)
            {
                int m = women[w][z];
                if(m == anti)
                    break; 
                else if(m == i)
                {
                    w_marriage[w] = i;              
                    m_marriage[i] = w;

                    for(int x = 1; x <= n; ++x)
                    {
                        if(man[anti][x] == w)
                        {
                            find(anti, x + 1);
                            return;
                        }
                    }
                }
            }
        }
    }
}

int
main(void)
{
    int t, p;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(w_marriage + 1, 0, sizeof(int) * n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &p);

            for(int j = 1; j <= n; ++j)
                scanf("%d", &women[i][j]);
        }

        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &p);

            for(int j = 1; j <= n; ++j)
                scanf("%d", &man[i][j]);
        }

        for(int i = 1; i <= n; ++i)
            find(i, 1);

        for(int i = 1; i <= n; ++i)
            printf("%d %d\n", i, m_marriage[i]);
    }

    return 0;
}
