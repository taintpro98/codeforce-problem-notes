#include <bits/stdc++.h>
using namespace std;

const int N=10e5+10;
const double eps = 10e-6;

int n, k, a[N];
double s[N], maxSuf[N];

bool check(double x)
{
    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - x;
    maxSuf[n + 1] = -(1e12);
    for(int i = n; i >= 1; i--)
         maxSuf[i] = max(maxSuf[i + 1], s[i]);
    for(int i = 1; i <= n - k + 1; i++)
        if (maxSuf[i + k - 1] >= s[i - 1]) return true;
    return false;
}

int main()
{
    freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    double first = -100000;
    double last = 100000;
    while (abs(first - last) >= eps)
    {
        double mid = (first + last) / 2;
        if (check(mid)) first = mid; else last = mid;
    }
    cout << first << endl;
    return 0;
}