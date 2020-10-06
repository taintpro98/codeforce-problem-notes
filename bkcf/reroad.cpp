#include <bits/stdc++.h>
using namespace std;
int n, q, res;
long long p, c;
int t[100001];
const long long INF = 1000000002;

int main(){
    // freopen("in.txt", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    t[0] = t[n+1] = INF;
    res = 0;
    for (int i=1; i<=n; i++) cin >> t[i], res += (t[i] == t[i-1]) ? 0:1;
    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> p >> c;
        res += (t[p-1] == t[p]) + (t[p] == t[p+1]);
        res -= (t[p-1] == c) + (c == t[p+1]);
        t[p] = c;
        cout << res << endl;
    }
    
    return 0;
}