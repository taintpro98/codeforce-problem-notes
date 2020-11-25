#include <bits/stdc++.h>
using namespace std;

int n, L1, L2, ans=0;
int a[1000002];
int S[1000002];

void solve(){
    deque<int> dq;
    for(int i=1; i<=n; i++){
        while(!dq.empty() && dq.front() < i-L2) dq.pop_front();
        if(i-L1 >= 1){
            while(!dq.empty() && S[dq.back()] < S[i-L1]) dq.pop_back();
            dq.push_back(i-L1);
        }
        S[i] = a[i] + (dq.empty() ? 0:S[dq.front()]);
        ans = max(ans, S[i]);
    }
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> L1 >> L2;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    solve();
    cout << ans << endl;
    return 0;
}
 