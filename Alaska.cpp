// 很简单的一道题目,将数据有序后,依次判断就可
// 唯一需要注意的就是题目中有个"back"也就是说
// 开过去了还有再开回来
#include <set>
#include <cstdio>
using namespace std;
#define fino 1422

set<int> locations;

int main(void)
{
    int n;
    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        locations.clear();
        int temp;
        while(n--)
        {
            scanf("%d", &temp);
            locations.insert(temp);
        }

        int last = 0;
        bool can = true;
        set<int>::iterator Iter = locations.begin();
        while(Iter != locations.end())
        {
            if(*Iter > last + 200)
            {
                can = false;
                printf("IMPOSSIBLE\n");
                break;
            }
            last = *Iter;
            ++Iter;
        }

        if(can)
        {
            if(fino - last > 100)
                printf("IMPOSSIBLE\n");
            else
                printf("POSSIBLE\n");
        }
    }
    return 0;
}

