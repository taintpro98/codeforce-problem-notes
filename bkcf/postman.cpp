#include <bits/stdc++.h>
using namespace std;

int n;
long k;
long long dist=0;
typedef pair<int, int> pii;
priority_queue<pii> a,b;

void sol(priority_queue<pii> &a){
    long d = k;
    while(!a.empty()){
        pii c = a.top();
        a.pop();
        if(d == k){
            dist += 2*c.first;
        }
        if (d<c.second){
            c.second -= d;
            a.push(c);
            d = k;
            
        } else {
            d -= c.second;
        }
    }
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int x, m;
        cin >> x >> m;
        long long q = m/k;
        m = m%k;
        dist += 2*q*abs(x);
        if (!m) continue;
        if(x >= 0){
            a.push(make_pair(x, m));
        } else {
            b.push(make_pair(-x, m));
        }
    } 
    sol(a);
    sol(b);
    cout << dist << endl;

    return 0;
}