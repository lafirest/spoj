// ���������������x��,����Ķ��պ�����.������5��,��һ����Ҫ2��,����Ҫ��8��.lcm(5,2)=10
// ��ʵ����ֻ��Ҫ��1��,2 * 3 - 5...ʵ�����ʼ���뷨�ǶԵģ���4������������celing(��)
// ������Ҫ���ķ���.��֪��զ���,���������ô����,������С������,Ȼ������С�����������
// ��Լ��,Ȼ�������Ҫ���ĸ���...

#include <stdlib.h>
#include <stdio.h>

int arr[8] = {0};
int r[4] = {0};

int gcd(int a, int b)
{
	int t = 0;
	while(b > 0)
	{
		t = a%b;
		a = b;
		b = t;
	}

	return a;
}

int lcm(int a, int b)
{
	if (a && b)
		return a * b / gcd(a, b);
	return 0;
}

int main(void)
{
	int i, v;
	while(1)
	{
		for(i = 0; i < 8; ++i)
			scanf("%d", &arr[i]);

		if(arr[0] == -1)
			break;

		// ����ͳ������,��Ҫ�ĸ���Ӧ����arr[i]/arr[i+4],�����������������ȡ��
		// Ϊʲô���뵽��lcm...��ô���
		for(i = 0; i < 4; ++i)
			r[i] = lcm(arr[i], arr[i+4]);

		for(i = 1; i < 4; ++i)
			r[0] = gcd(r[0], r[i]);

		r[1] = 0;
		if(r[0])
		{
			for(i = 1; i < 4; ++i)
			{
				v = arr[i] / r[0];
				if(v > r[1])
					r[1] = v;
			}
		}

		for(i = 0; i < 3; ++i)
			printf("%d ", arr[i+4] * r[1] - arr[i]);

		printf("%d\n", arr[7] * r[1] - arr[3]);
	}

	return 0;
}

/* github �ϵ�ac��
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
using namespace std;
int main(){
while(true){
int a[8];
int quantity=-1;
for(int i=0;i<8;i++){
scanf("%d",&a[i]);
}
if(a[0]==-1)
break;
for(int i=0;i<4;i++){
quantity=max(double(quantity),ceil(double(a[i])/double(a[i+4])));
}
for(int i=0;i<4;i++){
int temp;
temp=quantity*a[i+4]-a[i];
printf("%d",temp);
if(i<3)
printf(" ");
}
printf("\n");
}
return 0;
}*/