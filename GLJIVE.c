#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	int n=10,minabs=100,dp=0,r=0,v,dpabs;
	while(n--)
	{
		scanf("%d", &v);
		dp = dp + v;
		dpabs = abs(100 - dp);
		if(dpabs < minabs)
		{
			minabs = dpabs;
			r = dp;
		}
		else if(dpabs == minabs && dp > r)
			r = dp;
	}

	printf("%d\n", r);
	return 0;
}