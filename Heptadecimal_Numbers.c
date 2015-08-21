// 字符串解析类型的题目,不需要实际计算出对应的17进制数字的值
#include <stdio.h>

char unua[100000];
char dua[100000];

int
main(void)
{
    while(1)
    {
        int ulen = 0;
        int dlen = 0;
        char t = 0;
        char check_zero = 1;

        // 分别读取两个数字,忽略开头的0
        while(1)
        {
            t = getchar();
            if(t < 33)
                break;

            if(check_zero)
            {
                if(t == '0')
                    continue;
                else
                {
                    unua[ulen] = t;
                    check_zero = 0;
                    ++ulen;
                }
            }
            else
            {
                unua[ulen] = t;
                ++ulen;
            }
        }

        check_zero = 1;
        while(1)
        {
            t = getchar();
            if(t < 33)
                break;

            if(check_zero)
            {
                if(t == '0')
                    continue;
                else
                {
                    dua[dlen] = t;
                    check_zero = 0;
                    ++dlen;
                }
            }
            else
            {
                dua[dlen] = t;
                ++dlen;
            }
        }

        if(unua[0] == '*')
            break;

        // 通过长度判断哪个数更大
        if(ulen < dlen)
            printf("<\n");
        else if(ulen > dlen)
            printf(">\n");
        else
        {
            // 长度相等,逐个字节扫描,遇到不相等的就结束
            char equalp = 1;
            for(int i = 0; i < ulen; ++i)
            {
                if(unua[i] < dua[i])
                {
                    equalp = 0;
                    printf("<\n");
                    break;
                }
                else if(unua[i] > dua[i])
                {
                    equalp = 0;
                    printf(">\n");
                    break;
                }
            }

            if(equalp) 
                printf("=\n");
        }
    }

    return 0;
}
