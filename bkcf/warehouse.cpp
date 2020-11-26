#include <bits/stdc++.h>
using namespace std;

int n, T, D;
int a[1002];
int t[1002];
int dp[1002][102];
int ans=0;

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> T >> D;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> t[i];

    for(int x=1; x<=n; x++){
        for(int k=t[x]; k<=T; k++){
            for(int i=max(x-D, 0); i<=x-1; i++){
                dp[x][k] = max(dp[x][k], dp[i][k-t[x]] + a[x]);
            }
            ans = max(ans, dp[x][k]);
        }
    }    
    cout << ans << endl;

    return 0;
}