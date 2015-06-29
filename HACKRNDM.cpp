// 时间复杂度O((n+1)logn),评论里面有说O(n)的,不知道是不是用计数排序的方法
// 但那样要申请2^31个char空间内存耗用太大
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int n,k,v,next,acc;
    map<int,bool> nmap;
    cin >> n >> k;
    while(n--)
    {
        cin >> v;
        nmap[v] = false;
    }

    acc = 0;
    map<int,bool>::iterator Iter;
    map<int,bool>::iterator CIter;
    for(Iter = nmap.begin(); Iter != nmap.end(); ++Iter)
    {
        if(Iter->second)
            continue;
        else
        {
            next = Iter->first + k;
            while(true)
            {
                CIter = nmap.find(next);
                if(CIter == nmap.end())
                    break;
                else
                {
                    ++acc;
                    next += k;
                    CIter->second = true;
                }
            }
        }
    }

    cout << acc << endl;
    
    return 0;
}
