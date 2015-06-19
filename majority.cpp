#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

int main(void)
{
    int t,n,h,tmp;
    scanf("%d", &t);
    map<int, int> counter;
    while(t--)
    {
        counter.clear();
        scanf("%d", &n); 
        h = n >> 1;
        while(n--)
        {
            scanf("%d", &tmp);
            ++counter[tmp];
        }
        map<int, int>::iterator iter = counter.begin();
        bool have = false;
        for(; iter != counter.end(); ++iter)
        {
            if(iter->second > h)
            {
                printf("YES %d\n", iter->first);
                have = true;
                break;
            }
        }
        if(!have)
            printf("NO\n");
    }
    return 0;
}
