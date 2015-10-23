//http://www.cnblogs.com/codershell/p/3339809.html
//这里原理和2一样,但是回溯方法不一样
//用时:0.01s 速度很快...
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char str[100010];
int main(int argc, char *argv[])
{
    while (gets(str))
    {
        int n = strlen(str);
        int l = 0,r = n - 1;
        while (l < r)
        {
            // 3.区别就在这儿里,在版本2里面,如果前面的状态是相等,然后遇到了不相等的
            // 则放弃搜索,进行回溯.而这里则是,如果遇到了不相等的,不里面进行回溯,而是
            // 将右边向后移动.如果移动到底里,都没有合适的,才回溯.如果有相等的,则继续
            // 搜索
            while (r < n && str[l] != str[r]) 
                ++r;
            if (r >= n) 
            {
                // 2.如果不相等,且右边到底了,进行回溯,起点向右移动
                ++l;
                r = n - 1;
            }
            else 
            {
                // 1.如果左右相等,向内推进
                ++l;
                --r;
            }

            // 4.判断,左右相遇时,从两个搜索点分别向两边校验,如果都相等,则这个字符串右边最长的回文
            // 子串.如果有不相等的,则右边向后继续搜索.
            //
            // 这个算法和2的区别是,2是起点向右移动,这里是尾起点向后移动.然后回溯的方法不同
            if (r <= l)
            {
                int i = l,j = r;
                while (j < n && str[i] == str[j]) 
                {
                    --i;
                    ++j;
                }

                if (j < n) 
                    ++r;
            }
        }
        for (int i = 0; i <= l; ++i)
            putchar(str[i]);

        for (int i = r - 1;i >= 0; --i)
            putchar(str[i]);

        putchar('\n');
    }
    return 0;
}
