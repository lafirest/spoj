#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 50000 * 4 + 10
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define max(x,y) ((x) > (y) ? (x) : (y))  
#define INF -11000

struct node
{
	int max;
	int sum;
	int lmax;
	int rmax;

	node(int x=0)
	{
		max = sum = lmax = rmax = x;
	}
};

node arr[MAX] = {0};

void update_node(node *p, node *x, node *y)
{
	p->sum = x->sum + y->sum;
	p->max = max(max(x->max, y->max), x->rmax + y->lmax);
	p->lmax = max(x->lmax, x->sum + y->lmax);
	p->rmax = max(y->rmax, y->sum + x->rmax);
}

// gen_node这儿构建了node,并且返回
// 外部使用的地方又拷贝值，所以效率不高
// arr本身就是node数组,所以这儿可以传指针进来,
// 将gen_node,使用update_node替换掉
node gen_node(node *x, node *y)
{
	node p(0);
	update_node(&p, x, y);
	return p;
}

void build(int p, int l, int r)
{
	int temp = 0;
	if(l == r)
	{
		cin >> temp;
		arr[p] = node(temp);
	}
	else
	{
		int mid = (l + r) >> 1;
		build(left(p), l, mid);
		build(right(p), mid + 1, r);
		arr[p] = gen_node(arr + left(p), arr + right(p));
	}
}

node query(int p, int l, int r, int s, int e)
{
	if(s<=l && r <= e)
		return arr[p];
	else
	{
		node x(INF);
		node y(INF);
		x.sum = y.sum = 0;
		int mid = (l + r) >> 1;
		if(s <= mid)
			x = query(left(p), l, mid, s, e);

		if(mid < e)
			y = query(right(p), mid + 1, r, s, e);
		
		return gen_node(&x, &y);
	}
}

void update(int p, int l, int r, int u, int v)
{
	if (l == u && r == u)
	{
		arr[p] = node(v);
	}
	else
	{
		int mid = (l + r) >> 1;
		if (u <= mid)
			update(left(p), l, mid, u, v);
		else
			update(right(p), mid + 1, r, u, v);

		update_node(arr + p, arr + left(p), arr + right(p)); 
	}
}

int main(void)
{
	int n,opn;
	cin >> n;
	build(1, 1, n);
	cin >> opn;
	while(opn--)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if(op)
		{
			node r = query(1, 1, n, x, y);
			cout << r.max << endl;
		}
		else
		{
			update(1, 1, n, x, y);
		}
	}
	return 0;
}