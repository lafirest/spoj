// ʹ�ù��ɷ�,�ҹ���
#include <stdio.h>

int main(void)
{
	int t,n;
	scanf("%d", &t);
	while(t--)
	{	
		scanf("%d", &n);
		printf("%d\n", (n + 1) >> 1);
	}
}