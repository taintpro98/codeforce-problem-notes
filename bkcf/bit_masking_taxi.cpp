#include <bits/stdc++.h>
using namespace std;

#define MAXMASK 8192
#define MAXROAD 10000

int c[23][23];
int dp[12][MAXMASK];
long long limit;
int ans;
int n;

int solve(int idx, long long mask){
    if (mask == limit) 
       return c[idx][0];

    if(dp[idx][mask] != -1)
        return dp[idx][mask];

    int ret = MAXROAD;

    for (int i=0; i<=n; i++) 
    { 
        if ((mask & (1<<i)) == 0) 
        { 
            int newMask = mask | (1<<i); 
            ret = min( ret, solve(i, newMask) + c[idx][i]); 
        } 
    } 
  
    // adding memoization and returning 
    return dp[idx][mask] = ret;
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin >> c[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i != j) c[i][j] = c[i][i+n] + c[i+n][j];
        }
    }

    limit = (1<<(n+1)) - 1;
    memset(dp, -1, sizeof(dp));
    ans = solve(0, 1);
    cout << ans << endl;
    return 0;
}