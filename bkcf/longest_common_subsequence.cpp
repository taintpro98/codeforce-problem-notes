#include <bits/stdc++.h>
using namespace std;

int n, m;
int X[10003], Y[10003];
int dp[10003][10003];
int ans = 0;

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> X[i];
    }
    for(int i=1; i<=m; i++){
        cin >> Y[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(X[i] != Y[j]) dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j-1] + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}