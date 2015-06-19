// 求最大值问题,需要注意的是,每次进入循环时记得重置MG和MM的值
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int n, temp, NG=0,NM=0,MG=0,MM=0;
    scanf("%d", &n);
    while(n--)
    {
        MG = 0;
        MM = 0;
        scanf("%d %d", &NG, &NM);
    //    if (!NG && NG == NM)
     //       printf("uncertain\n");
      //  else
        {
            while(NG--)
            {
                scanf("%d", &temp);
                if(temp > MG)
                    MG = temp;
            }

            while(NM--)
            {
                scanf("%d", &temp);
                if(temp > MM)
                    MM = temp;
            }
            if(MM > MG)
                printf("MechaGodzilla\n");
            else
                printf("Godzilla\n");
        }
    }
    return 0;
}
