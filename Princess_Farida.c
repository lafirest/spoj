#include <stdio.h>

#define max(a,b) (a) > (b) ? (a) : (b);
long long dp[10004] = {0};
int main(void)
{
	int n,t,i,v,j;
	scanf("%d",&n);

	for(j=1; j <= n; ++j)
	{
		scanf("%d",&t);
		for(i = 2; i < t + 2; ++i)
		{
			scanf("%d",&v);
			dp[i] = max(v + dp[i-2], dp[i-1]);
		}
		printf("Case %d: %lld\n", j, dp[i-1]);
	}

	return 0;
}