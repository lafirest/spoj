// dp ����
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

		// ��һ�в����κδ���, Ҳ�����ȴ����һ��,���ڶ��е�һ��ʼ��Ҫ���⴦��,����û��Ҫ�����һ��
		for(i = 0; i < 3; ++i)
			scanf("%d", &dp[p][i]);

		if(n == 1)
			printf("%d. %d\n", k, dp[p][1]);
		else
		{
			p = !p;
			// ��Ϊ��һ��û��������,���Եڶ���Ҫ������������Ĳ�ͬ·���Ĵ�С
			
			// ��һ��ֻ�ܴ�������
			scanf("%d", &dp[p][0]);
			dp[p][0] += dp[!p][1], 

			// �ڶ���������·��
			scanf("%d", &dp[p][1]);
			dp[p][1] += min(min(dp[p][0], dp[!p][1]), dp[!p][1] + dp[!p][2]);

			// ������������·��
			scanf("%d", &dp[p][2]);
			dp[p][2] += min(min(dp[p][1], dp[!p][1]), dp[!p][1] + dp[!p][2]);

			p = !p;

			for(i = 2; i < n; ++i)
			{
				l = !p;

				// ��Ϊ�ڶ����Ѿ����˴���,����ǰһ��ÿ�����������������Ǹ������Сcost

				// ��һ��������·��
				scanf("%d", &dp[p][0]);
				dp[p][0] += min(dp[!p][0], dp[!p][1]);

				// �ڶ���������·��
				scanf("%d", &dp[p][1]);
				dp[p][1] += min(min(min(dp[p][0], dp[l][0]), dp[l][1]), dp[l][2]);

				// ������������·��
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
