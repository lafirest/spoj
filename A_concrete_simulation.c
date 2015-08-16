// 用两个数组来维护正向的行列映射,用两个数组来维护逆向的行列映射
// 错了3次,因为把Q里面把colmap写成了rowmap
#include <stdio.h>

#define calc(x, y) ((x - 1) * 5678 + y)

int rowmap[1235];
int rrowmap[1235];
int colmap[5679];
int rcolmap[5679];

int
main(void)
{
    char c;
    int x, y;

    while(1 == scanf("%c", &c))
    {
        switch(c)
        {
            case 'R':
            {   
                scanf("%d %d", &x, &y);
                int xm = rowmap[x];
                int ym = rowmap[y];
                
                if(xm)
                    rowmap[y] = xm;
                else
                    rowmap[y] = x;

                if(ym)
                    rowmap[x] = ym;
                else
                    rowmap[x] = y;

                rrowmap[rowmap[y]] = y;
                rrowmap[rowmap[x]] = x;
            }
            break;
            case 'C':
            {
                scanf("%d %d", &x, &y);
                int xm = colmap[x];
                int ym = colmap[y];
                
                if(xm)
                    colmap[y] = xm;
                else
                    colmap[y] = x;

                if(ym)
                    colmap[x] = ym;
                else
                    colmap[x] = y;

                rcolmap[colmap[y]] = y;
                rcolmap[colmap[x]] = x;
            }
            break;
            case 'Q':
            {
                scanf("%d %d", &x, &y);
                int xm = rowmap[x] ? rowmap[x] : x;
                int ym = colmap[y] ? colmap[y] : y;
                printf("%d\n", calc(xm, ym));
            }
            break;
            case 'W':
            {
                scanf("%d", &x);
                int xm = x / 5678;
                int ym = x - 5678 * xm;

                if(ym == 0)
                    ym = 5678;
                else 
                    ++xm;

                if(rrowmap[xm])
                    xm = rrowmap[xm];

                if(rcolmap[ym])
                    ym = rcolmap[ym];


                printf("%d %d\n", xm, ym);
            }
            break;
        }
    }

    return 0;
}
