/* https://www.topcoder.com/community/data-science/data-science-tutorials/algorithm-games/ 
// 虽然知道怎么做了,但是还是不知道其中的数学原理,能用数学证明就好了
// 证明:
		对于点i,设X = {1, k, l}, Y = {i - 1, i - k, i - l}
		点i选择x(x 属于 X)后剩余y(y属于Y),则后续操作可以看做
		是交换先后手后以y为目标的一个新游戏,或者子游戏.所以对
		点i的求解,等同于对这个新游戏的求解,而新游戏交换了先后手,
		所以点i时先手想要获胜的条件是存在一个y的结果为输的新游戏.
		这个能看做是个dp问题,每一局的胜负取决与之前的子游戏的最优解( 这里是输)
*/
#include <stdio.h>

#define MAX 1000005

char arr[MAX] = {0};

int main(void)
{
	int i, k, l, n, kp, lp;
	scanf("%d %d %d", &k, &l, &n);
	for(i = 1; i < MAX; ++i)
	{
	//	if(i == k || i == l)
	//		arr[i] = 1;    error
		// 这里注意看题目可以使用的金币是1, k ,l 3个,而不是k l两个
		if(i - 1 >= 0 && !arr[i - 1])
			arr[i] = 1;
		else 
		{
			kp = i - k;
			lp = i - l;
			if(kp >= 0 && !arr[kp])
				arr[i] = 1;
			else if(lp >= 0 && !arr[lp])
				arr[i] = 1;
		}
	}
	
	while(n--)
	{
		scanf("%d", &i);
		printf("%c", 65 + !arr[i]);
	}
	printf("\n");
	return 0;
}