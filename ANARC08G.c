#include <stdio.h>

#define MAX 1001
int bank[MAX][MAX];     // 银行间相互欠账关系
int owing[MAX];         // 每个银行应该偿还的债务

int
main(void)
{
    int t = 0;
    while(1)
    {
        ++t;
        int n; 
        int max = 0;
        int min = 0;
        scanf("%d", &n);
        if(!n)
            break;

        for(int i = 1; i <= n; ++i)
        {
            owing[i] = 0;

            for(int j = 1; j <= n; ++j)
            {
                int temp = 0;
                scanf("%d", &temp);
                bank[i][j] = temp;

                max += temp;                // 记录债务涉及的总资金
                owing[i] += temp;           // 记录该银行欠的钱的总数
            }
        }

        for(int i = 1; i <= n; ++i)
        {
            int due = 0;
            for(int j = 1; j <= n; ++j)
                due += bank[j][i];          // 计算该银行应该获得的钱

            // 用应该获得的钱 - 应该偿还的钱
            // 此时owing[i]代表的是化简后结余的钱
            if(due >= owing[i])
                owing[i] = due - owing[i];
            else
                owing[i] = owing[i] - due;
        }

        // 统计所有银行化简后涉及的钱
        for(int i = 1; i <= n; ++i)
            min += owing[i];

        // min / 2,是因为债务是双向的,也就是说同一笔钱,在owing里面,实际上存了两份
        printf("%d. %d %d\n", t, max, min / 2);
    }

    return 0;
}
