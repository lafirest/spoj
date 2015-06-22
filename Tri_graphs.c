// dp 问题
#include <stdio.h>

#define min(a,b) ((a) < (b) ? (a) : (b))

int dp[2][3] = {0};

int main(void)
{
	int k=0,n,p=0,i,l;
	while(++k)
	{
		scanf("%d", &n);
		if(!n)
			break;

		// 第一行不做任何处理, 也可以先处理第一行,但第二行第一列始终要特殊处理,所以没必要处理第一行
		for(i = 0; i < 3; ++i)
			scanf("%d", &dp[p][i]);

		if(n == 1)
			printf("%d. %d\n", k, dp[p][1]);
		else
		{
			p = !p;
			// 因为第一行没有做处理,所以第二行要计算从起点出发的不同路径的大小
			
			// 第一列只能从起点过来
			scanf("%d", &dp[p][0]);
			dp[p][0] += dp[!p][1], 

			// 第二列有三条路径
			scanf("%d", &dp[p][1]);
			dp[p][1] += min(min(dp[p][0], dp[!p][1]), dp[!p][1] + dp[!p][2]);

			// 第三列有三条路径
			scanf("%d", &dp[p][2]);
			dp[p][2] += min(min(dp[p][1], dp[!p][1]), dp[!p][1] + dp[!p][2]);

			p = !p;

			for(i = 2; i < n; ++i)
			{
				l = !p;

				// 因为第二行已经做了处理,所以前一行每个点代表从起点出发到那个点的最小cost

				// 第一列有两条路径
				scanf("%d", &dp[p][0]);
				dp[p][0] += min(dp[!p][0], dp[!p][1]);

				// 第二列有四条路径
				scanf("%d", &dp[p][1]);
				dp[p][1] += min(min(min(dp[p][0], dp[l][0]), dp[l][1]), dp[l][2]);

				// 第三列有三条路径
				scanf("%d", &dp[p][2]);
				dp[p][2] += min(min(dp[p][1], dp[l][1]), dp[l][2]);

				p = !p;
			}

			p = !p;
			printf("%d. %d\n", k, dp[p][1]);
		}
	}

	return 0;
}
