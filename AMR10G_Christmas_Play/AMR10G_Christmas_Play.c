#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20000+50;
const int inf = ~0u >> 1;

int T, k, n;
int h[maxn];

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++)
            scanf("%d", h+i);
        sort(h, h+n);
        int ans = inf;
        for(int i = 0; i+k <= n; i++)
            ans = min(h[i+k-1]-h[i], ans);
        printf("%d\n", ans);
    }
    return 0;
}
