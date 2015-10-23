// 这道题目的思路就是在字符串的右边找到一个最长的回文子串
// 1.如果字符串原本就是回文直接输出
// 2.字符串不存在回文字串,直接复杂字符串的倒序输出
// 3.右边存在一个回文字串,则以这个子串为轴扩展字符串
//
// 这里的算法是:
// 1.分别从头和尾进行比对,如果相同则向里推进
// 2.如果不同,则左边的起点+1,右边返回最后,重复,直到头尾相遇
// 这个解法会tle,因为这种回溯查找的复杂度是n^2
#include <stdio.h>
#include <string.h>

char buffer[100001];

int 
main(void)
{
    while(gets(buffer))
    {
        int end = strlen(buffer) - 1;
        int i = 0;
        int j = end;
        int si = i;
        while(i <= j && si <= end)
        {
            // 左右相等,向里面推进
            if(buffer[i] == buffer[j])
            {
                ++i;
                --j;
            }
            else
            {
                // 不相等,回溯,起点向右移动
                si += 1;
                if(si == end)
                    break;
                else
                {
                    i = si;
                    j = end;
                }
            }
        }

        // 输出
        for(int i = 0; i <= end; ++i)
            putchar(buffer[i]);

        --si;
        for(; si >= 0; --si)
        {
            putchar(buffer[si]);
        }

        putchar('\n');

    }

    return 0;
}

