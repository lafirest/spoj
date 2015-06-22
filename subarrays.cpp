// ������õ���dp,��Ч�ʲ���.�о��߶�������Ҳ����
// ����������˵O(n)���㷨,��ʱû�뵽
#include <iostream>
using namespace std;

#define max(a,b) (a) > (b) ? (a) : (b)
int arr[1000000] ={0};			// ��������

// �������ܴ�,�޷����������㹻���ڴ�,��ÿ��״ֻ̬����һ��״̬���
// ��������ֻ��Ҫ������������Ϳ�����
int dp[2][1000000] = {0};		

int main(void)
{
	int i, n, k, t, p=1;
	cin >> n;
	for(i = 0; i < n; ++i)
	{
		// ��ȡ����,����ʼ��dp�����һ��
		cin >> t;
		dp[0][i] = t;
		arr[i] = t;
	}

	cin >> k;
	
	// dp�����������תʹ��
	// j -> k
	for(int j = 1; j < k; ++j)
	{
		// dp[p][i] Ϊ��һ�е�״̬���¼ӽ�����arr[i-j]֮������ֵ
		for(i = j; i < n; ++i)
			dp[p][i] = max(dp[!p][i], arr[i-j]);

		p = !p;
	}

	// ��ת�µõ��������
	p = !p;

	i = k - 1;
	for(; i < n - 1; ++i)
		cout << dp[p][i] << " ";

	cout << dp[p][i] << endl;

	return 0;
}
