// http://blog.csdn.net/zuihoudebingwen/article/details/8018445
#include <algorithm>  
#include <cstdio>  
using namespace std;  
#define lc cur << 1  
#define rc (cur << 1) + 1  
const int MAXN = 50000, INF = 1000000000;  
struct interval_tree  
{  
    struct data  
    {  
        int alls, maxs, maxl, maxr;  
        inline data(int x = 0)  
        {  
            alls = maxs = maxl = maxr = x;  
        }  
    } d[MAXN << 2];  
    inline data update(data x, data y)  
    {  
        data ret;  
        ret.alls = x.alls + y.alls;  
        ret.maxs = max(x.maxr + y.maxl, max(x.maxs, y.maxs));  
        ret.maxl = max(x.maxl, x.alls + y.maxl);  
        ret.maxr = max(y.maxr, y.alls + x.maxr);  
        return ret;  
    }  
    void build(int cur, int f, int t)  
    {  
        if (f == t)  
        {  
            int x;  
            scanf("%d", &x);  
            d[cur] = data(x);  
            return;  
        }  
        int mid = f + t >> 1;  
        build(lc, f, mid);  
        build(rc, mid + 1, t);  
        d[cur] = update(d[lc], d[rc]);  
    }  
    data query(int cur, int f, int t, int qf, int qt)  
    {  
        if (qf <= f && t <= qt)  
            return d[cur];  
        data x(-INF), y(-INF);  
        x.alls = y.alls = 0;  
        int mid = f + t >> 1;  
        if (qf <= mid)  
            x = query(lc, f, mid, qf, qt);  
        if (qt > mid)  
            y = query(rc, mid + 1, t, qf, qt);  
        return update(x, y);  
    }  
} it;  
int main()  
{  
    int n, m;  
    scanf("%d", &n);  
    it.build(1, 1, n);  
    scanf("%d", &m);  
    while (m --)  
    {  
        int x, y;  
        scanf("%d%d", &x, &y);  
        printf("%d\n", it.query(1, 1, n, x, y).maxs);  
    }  
    return 0;  
}  
