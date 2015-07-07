/* 
 * 对于trans2int f(x) = sigma(i = 1, length(x), v(x[i]))
 *      r = r + k * cv(x), k = 1   x belong [IXCM]
 * v(x) 
 *      k = cv(x)                 x belong [2 .. 9]
 * cv(x) -> ascii(x) - 48
 * 最后如果k 不等于 1,则说明是以数字结尾需要加上k
 * trans2str的数学模型没搞好,所以在这上面浪费了很多调试时间
 */
#include <stdio.h>

short map[125];
char rmap[4] = {'i', 'x', 'c', 'm'};
char buffer1[1024];
char buffer2[1024];

int trans2int(char *str)
{
    int k = 1, r = 0;
    char c;
    while((c = *str))
    {
        if(c >= 'c')
        {
            r += map[c] * k;
            k = 1;
        }
        else
            k = map[c];

        ++str;
    }

    if(k == 1)
        return r;
    else 
        return r + k;
}

void trans2str(char *str, int val1, int val2)
{
    int m = 0, i = 0, j, p;
    char temp;
    int sum = val1 + val2;

    while(sum)
    {
        // 除10分解
        p = sum % 10;
        if(p)
        {
            // 输出该位的基数
            str[i] = rmap[m];
            ++i;

            // 余数为1不需要输出
            if(p != 1)
            {
                str[i] = p + 48;
                ++i;
            }
        }
            
        sum = sum / 10;
        ++m;
    }

    str[i] = '\0';
    --i;

    // 倒序
    for(j = 0 ;i > j; --i, ++j)
    {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
}

int main(void)
{
    int i, t;
    for(i = 2; i < 10; ++i)
        map[i + 48] = i;

    map['m'] = 1000;
    map['c'] = 100;
    map['x'] = 10;
    map['i'] = 1;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %s", buffer1, buffer2);
        trans2str(buffer1, trans2int(buffer1), trans2int(buffer2)),
            printf("%s\n", buffer1);
    }

    return 0;
}
