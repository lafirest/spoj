/* githup 上的答案,因为知道怎么做,但高中物理都忘记了
http://en.wikipedia.org/wiki/Projectile_motion
http://www.physicsclassroom.com/Class/vectors/U3L2e.cfm
http://physics.gmu.edu/~amin/phys251/Topics/ScientificComputing/sprojectileMotion.html
*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int 
main(void)
{
    int t, ta, sp;
    double angle;

    scanf("%d", &t); 
    for(int i = 1; i <= t; ++i)
    {
        scanf("%d%d", &ta, &sp);
        angle = asin((9.806 * ta) / (sp * sp));
        angle /= 2;
        angle *= 180.0;
        angle /= PI;

        printf("Scenario #%d: ", i);
        if(angle <= 45.000000000000)
            printf("%.2lf\n", angle);
        else
            printf("-1\n") ;
    }

    return 0 ;
}
