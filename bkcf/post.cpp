#include <bits/stdc++.h>

using namespace std;

struct customer
{
	int c, t;	
};

bool cmp(struct customer x, struct customer y)
{
	return x.t < y.t;
}

int n, f[10010][50], tt;
struct customer a[10010];

int cal(int x, int t)
{
	if (x > n || t == tt) return 0;
	if (f[x][t] != -1) return f[x][t];
	int res = cal(x + 1, t);
	if (t <= a[x].t) res = max(res, cal(x + 1, t + 1) + a[x].c);
	f[x][t] = res;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> tt;
	for(int i = 1; i <= n; i++)
		cin >> a[i].c >> a[i].t;
	sort(a + 1, a + n + 1, cmp);
	memset(f, 255, sizeof(f));
	cout << cal(1, 0);
}