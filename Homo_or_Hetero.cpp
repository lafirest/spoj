// stl的应用,这里用了两个map,分别记录:
// counter记录元素和这个元素的个数
// rc记录某个个数的元素有多少个.比如rc[2] = 3,代表当前有3个元素的个数是2
//
// 修改时两个map一起修改，判断时一起判断

#include <cstdio>
#include <map>
using namespace std;

typedef map<int,int> mapii;
typedef mapii::iterator mapiiter;

mapii counter;
mapii rc;
char buffer[12];

int main(void)
{
    int n, k; 

    scanf("%d", &n);
    while(n--)
    {
        scanf("%s %d", buffer, &k);

        if(buffer[0] == 'i')
        {
            int num = 0; 
            mapiiter iter = counter.find(k);
            if(iter != counter.end())
            {
                num = iter->second + 1;
                ++iter->second;
            }
            else
            {
                counter.insert(pair<int,int>(k,1));
                num = 1;
            }

            ++rc[num];
        }
        else
        {
            mapiiter iter = counter.find(k);
            if(iter != counter.end())
            {
                int num = iter->second;
                mapiiter rciter = rc.find(num);
                --rciter->second;
                if(rciter->second == 0)
                    rc.erase(rciter);
                
                --iter->second;
                if(iter->second == 0)
                    counter.erase(iter);
            }
        }

        int size = counter.size();
        if(size == 0)
            puts("neither");
        else if(size == 1)
        {
            mapiiter iter = counter.begin();
            if(iter->second >= 2)
                puts("homo");
            else 
                puts("neither");
        }
        else 
        {
            map<int, int>::reverse_iterator iter = rc.rbegin();

            if(iter->first >= 2)
                puts("both");
            else
                puts("hetero");
        }
    }

    return 0;
}
