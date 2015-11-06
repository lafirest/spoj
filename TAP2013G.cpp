// 这道题目初看很简单,用贪心+排序就行了,然而就会被坑一开始的做法是:对seq降序排序,quadr升序排序,然后逐个
// 比较两边的大小，直到遇到第一个小于的数.问题就出在这儿:
// 比如:seq:9 8 7 quadr:1 8 9，按照这种方法就只能成功一次,实际是两次7 对 1，9 对 8
// 所以改成都升序排,然后seq逐个找大于quadr的值
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 100010
int quadr[MAX];
int seq[MAX];

int read(void)
{
    int n = 0;
    char p = getchar();
    while(p < '0')
        p = getchar();

    while(p >= '0')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n;
}

int main(void)
{
    int n = read();
    for(int i = 0; i < n; ++i)
        quadr[i] = read();

    for(int i = 0; i < n; ++i)
        seq[i] = read();

    sort(quadr, quadr + n);
    sort(seq, seq + n); 

    int r = 0;
    for(int i = 0, j = 0; i < n && j < n; )
    {
        // 大于则双方都移到下一个元素
        if(seq[i] > quadr[j])
        {
            ++r;
            ++i;
            ++j;
        }
        else
            ++i;    // seq移到下一个元素
    }

    printf("%d\n", r);

    return 0;
}
