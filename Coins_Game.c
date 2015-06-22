/* https://www.topcoder.com/community/data-science/data-science-tutorials/algorithm-games/ 
// ��Ȼ֪����ô����,���ǻ��ǲ�֪�����е���ѧԭ��,������ѧ֤���ͺ���
// ֤��:
		���ڵ�i,��X = {1, k, l}, Y = {i - 1, i - k, i - l}
		��iѡ��x(x ���� X)��ʣ��y(y����Y),������������Կ���
		�ǽ����Ⱥ��ֺ���yΪĿ���һ������Ϸ,��������Ϸ.���Զ�
		��i�����,��ͬ�ڶ��������Ϸ�����,������Ϸ�������Ⱥ���,
		���Ե�iʱ������Ҫ��ʤ�������Ǵ���һ��y�Ľ��Ϊ�������Ϸ.
		����ܿ����Ǹ�dp����,ÿһ�ֵ�ʤ��ȡ����֮ǰ������Ϸ�����Ž�( ��������)
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
		// ����ע�⿴��Ŀ����ʹ�õĽ����1, k ,l 3��,������k l����
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