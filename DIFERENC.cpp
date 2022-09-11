// https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack
// https://oi-wiki.org/ds/monotonous-stack/
//
#include<iostream>
#include<cstdio>

const int max = 300100;
int arr[max];
int stack[max]; // monotonic stack of maximum positions

long long res;

long long calc(int n)
{
    int top = 1;
    long long tmp = 0;
    long long sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        while(top > 1 && arr[stack[top]] < arr[i]) 
        {
            tmp -= 1LL * (stack[top] - stack[top - 1]) * arr[stack[top]];
            --top;
        }
        tmp += 1LL * (i - stack[top]) * arr[i];
        sum += tmp;
        stack[++top] = i;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    // sum of max
    for(int i = 1; i <= n; ++i) 
    	scanf("%d", &arr[i]);
    res += calc(n);

    // sum of min
    for(int i = 1; i <= n; ++i) 
    	arr[i] = -arr[i];
    res += calc(n);

    printf("%lld\n",res);
    return 0;
}
