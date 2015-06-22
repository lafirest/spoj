#include <stdio.h>
#include <math.h>

int main(void)
{
	int x,y;
	long value,power,temp;
	while(1)
	{
		power = 0;
		scanf("%de%d", &x, &y);
		if(!x && !y)
			return 0;
       
		// 计算人的个数
		temp = value = (long)(x * pow(10, y));
		
		// 每次减半,计算需要的参数
		while(value > 1)
		{
			++power;
			value /= 2;
		}

		// result = 1 + 2 * k
		// k = value - 2^power
		// 数学不好没法证明,只能靠归纳...归纳不去来,只能去找其他人的题解了
		printf("%ld\n", (long)(1 + (temp - pow(2, power)) * 2));
	}
}