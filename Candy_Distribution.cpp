#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> student;
priority_queue<int, vector<int>, greater<int> > prices;

int main(void)
{
    int len, temp;
    unsigned long long value;
    while(true)
    {
        value = 0;
        scanf("%d", &len);
        if(!len)
            break;

        for(int i = 0; i < len; ++i)
        {
            scanf("%d", &temp);
            student.push(temp);
        }

        for(int i = 0; i < len; ++i)
        {
            scanf("%d", &temp);
            prices.push(temp);
        }

        for(int i = 0; i < len; ++i)
        {
            unsigned long long s = student.top();
            unsigned long long p = prices.top();
            student.pop();
            prices.pop();
            value += s * p;
        }
   
        printf("%llu\n", value);
    };
    
    return 0;
}
