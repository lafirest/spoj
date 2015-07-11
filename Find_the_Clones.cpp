// map+数组映射
#include <stdio.h>
#include <memory.h>
#include <map>
#include <string>
using namespace std;

map<string, int> dnas;
int arr[20001];

int main(void)
{
    int m,n;
    char buffer[125];
    while(true)
    {
        scanf("%d %d", &m, &n);
        if(m + n == 0)
            break;

        dnas.clear();
        memset(arr + 1, 0, (sizeof(int)) * n);
        for(int i = 1; i <= m; ++i)
        {
            scanf("%s", buffer);
            ++dnas[buffer];
        }

        map<string, int>::iterator Iter = dnas.begin();
        while(Iter != dnas.end())
        {
            ++arr[Iter->second];
            ++Iter;
        }

        for(int i = 1; i <= m; ++ i)
            printf("%d\n", arr[i]);
    }

    return 0;
}
