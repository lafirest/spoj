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
       
		// �����˵ĸ���
		temp = value = (long)(x * pow(10, y));
		
		// ÿ�μ���,������Ҫ�Ĳ���
		while(value > 1)
		{
			++power;
			value /= 2;
		}

		// result = 1 + 2 * k
		// k = value - 2^power
		// ��ѧ����û��֤��,ֻ�ܿ�����...���ɲ�ȥ��,ֻ��ȥ�������˵������
		printf("%ld\n", (long)(1 + (temp - pow(2, power)) * 2));
	}
}