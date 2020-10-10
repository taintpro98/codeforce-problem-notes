#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define pob pop_back
int n,k;
ll ans = 0;
priority_queue<pii> u,v;
void solve(priority_queue<pii> &q){
    int now = k;
    while (q.size())
    {
        pii x = q.top();
        q.pop();
        if(now == k){
            ans += 2 * x.first;
        }
        if(now >= x.second) {
            now -= x.second;
        }
        else{
            x.second -= now;
            now = k;
            q.push(x);
        }
    }
}
int main(){
    freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x,m;
        cin >> x >> m;
        ll num = m/k;
        ans += num * 2 * abs(x);
        if(m%k==0) continue;
        if(x >= 0){
            u.push(make_pair(x,m%k));
        } else v.push(make_pair(-x,m%k));
    }
    solve(u);
    solve(v);
    cout << ans << endl;
    return 0;
}