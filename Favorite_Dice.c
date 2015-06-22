// http://www.guokr.com/article/5583/
// https://en.wikipedia.org/wiki/Coupon_collector%27s_problem
// 关于gcc和vc double输出的文章 http://www.tuicool.com/articles/QrY3yy
#include <stdio.h>
int main(void)
{
	int t,n,i;
	double r;
	scanf("%d", &t);
	while(t--)
	{
		r = 0;
		scanf("%d", &n);
		for(i = 1; i <= n; ++i)
			r += (double)n / i;

		printf("%.2f\n", r);

	}
	return 0;
}
