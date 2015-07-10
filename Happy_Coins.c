//太简单了,简单到不敢相信能ac.就是找规律,lxh为奇数时就能获胜,这个可以看作异或操作
//所以lxl想要获胜的化,就需要在最后剩下一个l和一个h,而最后还剩下一个l的必要条件就是
//l为奇数,可以l和l进行消除得到想异的h,或则l和h进行消除得到h,这样下去只要l是基数最后就
//必然剩下一个
#include <stdio.h>

int main(void)
{
    int t, n, l;
    char buffer[10];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        l = 0;
        while(n--)
        {
            scanf("%s", buffer);
            if(*buffer == 'l')
                ++l;
        }

        if(l & 1)
            printf("lxh\n");
        else
            printf("hhb\n");
    }

    return 0;
}
