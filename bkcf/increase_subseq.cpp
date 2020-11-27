#include <bits/stdc++.h>
using namespace std;

int n;
int a[10002];
int ans=-1;
int dp[10002];

void solve(){
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<=i-1; j++){
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    solve();
    // for(int i=1; i<=n; i++) cout << dp[i] << " ";
    cout << ans << endl;

    return 0;
}