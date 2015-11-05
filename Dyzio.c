// http://www.algorithmist.com/index.php/SPOJ_DYZIO
// 1将字符串分半,然后0结束操作.这个实际上能看作是对
// 数的遍历,1代表是父节点,0代表是叶子节点
#include <stdio.h>

#define MAX 20010
char str[MAX];
int n;
int depth;
int count; 
int res;
int i;

// 这里就是使用ad-hoc的方法来做,结果tle了
/*int calc(int s, int e)
{
    int r = 0;
    if(s <= e)
    {
        if(str[s] == '1')
        {
            int len = e - s;
            if(len > 1)
            {

                int se = len / 2;
                if(len & 1)
                    ++se;

                ++r;
                r += calc(s, se);
                r += calc(se + 1, e);
            }
        }
    }

    return r;
}*/

// 这里把对字符串的遍历转换为对树的遍历,只需要O(n)就能完成
void visit(int lvl)
{
    if(i >= n)
        return;

    // 到了叶子节点,判断需不需要更新树的深度
    if(str[i] == '0')
    {
        if(lvl > depth)
        {
            depth = lvl;
            res = count;
        }

        ++i;
    }
    else
    {
        ++i;
        ++count;        // 当前cut的次数
        ++lvl;          // 当前访问的深度
        visit(lvl);
        visit(lvl);
    }
}

int main(void)
{
    int t = 10;
    while(t--)
    {
        count = 0;
        depth = 0;
        res = 0;
        i = 0;
        scanf("%d %s", &n, str);
        visit(0);
        printf("%d\n", res);
    }

    return 0;
}
