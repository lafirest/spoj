// 这道题用的是dp,但效率不高.感觉线段树或许也可以
// 评论里面有说O(n)的算法,暂时没想到
#include <iostream>
using namespace std;

#define max(a,b) (a) > (b) ? (a) : (b)
int arr[1000000] ={0};			// 保存输入

// 数据量很大,无法申请下来足够的内存,但每个状态只和上一个状态相关
// 所以这里只需要申请两行数组就可以了
int dp[2][1000000] = {0};		

int main(void)
{
	int i, n, k, t, p=1;
	cin >> n;
	for(i = 0; i < n; ++i)
	{
		// 读取输入,并初始化dp数组第一行
		cin >> t;
		dp[0][i] = t;
		arr[i] = t;
	}

	cin >> k;
	
	// dp数组的两行碾转使用
	// j -> k
	for(int j = 1; j < k; ++j)
	{
		// dp[p][i] 为上一行的状态和新加进来的arr[i-j]之间的最大值
		for(i = j; i < n; ++i)
			dp[p][i] = max(dp[!p][i], arr[i-j]);

		p = !p;
	}

	// 反转下得到结果数组
	p = !p;

	i = k - 1;
	for(; i < n - 1; ++i)
		cout << dp[p][i] << " ";

	cout << dp[p][i] << endl;

	return 0;
}
