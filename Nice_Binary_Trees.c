// 题目的需求是:给出一个完全二叉树(不是平衡二叉树)的前序遍历的字符串('n'代表父节点,'l'代表叶子节点),然后求出树的高度
// 这里的做法是:因为是完全二叉树,所以用堆的形式按照前序遍历的方式来构造树,但实际上并不需要存储树的具体
// 内容.构造树的时候记录下最大的位置,按照堆的性质,这个位置就是最深的一层,其log(n)则为当前树的高度
#include <stdio.h>
#include <math.h>

#define left(p) ((p) << 1)
#define right(p) (left(p) + 1)

int maxd;

void build(char p, int pos)
{
    // 父节点的位置
    if(pos > maxd)
        maxd = pos;

    // 左子树
    int left = left(pos);
    p = getchar();
    if(p == 'n')
        build(p, left);
    else
    {
        if(left > maxd)
            maxd = left;
    }

    // 右子树
    int right = right(pos);
    p = getchar();
    if(p == 'n')
        build(p, right);
    else
    {
        if(right > maxd)
            maxd = right;
    }
}

int main(void)
{
    // io方面,后面的字符串采用在线的方式处理,读取时构造树,而不是用scanf读取完后再构造,速度提高一倍
    // 至于t只有一个数据,所以没必要用fast io技巧
    int t, d;
    scanf("%d\n", &t);

    while(t--)
    {
        maxd = 0;
        char p;

        // 读取空白符等
        do
        {   
            p = getchar();
        }while(p != 'n' && p != 'l');

        // 第一个字符为l的不是树,不用构造
        if(p == 'n')
            build(p, 1);

        // 高度不为0的求树的高度
        if(maxd)
            maxd = log2(maxd);

        printf("%d\n", maxd);
    }

    return 0;
}
