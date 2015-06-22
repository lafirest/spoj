// http://math.stackexchange.com/questions/8611/number-of-common-divisors-between-two-given-numbers
// https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a %b) : a;
}


int main(void)
{
	int n, x, y,g,r,sqr,i;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d", &x, &y);
		// 求两个数的最大公约数
		g = gcd(x, y);
		r = 0;
		sqr = (int)sqrt(g);

		// 从1到sqrt(g)求因数个数
		for (i = 1; i <= sqr; ++i)
			if(g % i == 0)
			{
				// 能够被整除,则有两个因数i, g/i
				r += 2;

				// 如果i == g / i,则只有一个因数i
				if(i == g / i)
					--r;
			}
		printf("%d\n", r);
	}
	return 0;
}