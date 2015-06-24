#include<cstdio>
#include<map>
using namespace std;
#define MAX 500005 

int arr[MAX] = {0};

// 这个map改成数组估计也可以,虽然浪费了空间,但是效率更好
map<int,bool> value;

// 求序列对应位置的值,这儿不用递归来做,因为当数比较大时递归
// 效率不佳.这儿使用循环来做,且对每个位置的值进行记忆化,避免
// 同一位置反复求值
// 求查询的最大值或则直接构建到MAX,可以将后续查询转变为数组下标查询
// 那样估计效率更好
int f(int x)
{
    // 如果该位置已经被求值过,直接返回
    if(arr[x])
        return arr[x];
    else
    {
        // 没有则像前找最近的一个求过值的位置
        int i = x - 1, v;
        for(; i > 0; i--)
            if(arr[i])
                break;

        // 从这个位置起,向后构建序列
        for(; i < x; ++i)
        {
            v = arr[i] - i - 1; 
            if(v <= 0 || value[v])
                v = arr[i] + i + 1;
        
            // 记忆化
            arr[i + 1] = v;
            value[v] = true;
        }

        return arr[x];
    }
}

int main(void)
{
    int n;
    while(true)
    {
        scanf("%d",&n);
        if(n == -1)
            break;
        else
            printf("%d\n", f(n));
    }

    return 0;
}
