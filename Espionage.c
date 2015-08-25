// 集合问题,有两种情况会出现"spied"
// 1.一个公民出现在了间谍的集合里面
// 2.一个间谍出现在了公民的集合里面
#include <stdio.h>

#define MAX 1010
int spies[MAX];         //间谍集合
int civilians[MAX];     //公民集合
char* result[2] = {"spying", "spied"};
int color = 1;

int
main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i)
    {
        int n, r;
        int spied = 0;
        scanf("%d %d", &n, &r);
        while(r--)
        {
            int r1, r2;
            scanf("%d %d", &r1, &r2);

            if(!spied)
            {
                if(spies[r2] == color)  // 判断被监视的公民是否也是间谍
                    spied = 1;
                else if(civilians[r1] == color) // 判断监视的间谍是否也在被监视的集合里
                    spied = 1;

                // 染色
                spies[r1] = color;
                civilians[r2] = color;
            }
        }

        printf("Scenario #%d: %s\n", i, result[spied]);
        ++color;
    }

    return 0;
}
