#include <bits/stdc++.h>
using namespace std;

#define MAXMASK 8388607
#define MAXROAD 10000

int n, k;
int c[24][24];
int ans;
int dp[24][MAXMASK];
long long limit;

bool check(int idx, long long mask, int load){
    if(idx > n && (mask & (1<<(idx-n))) != 0){
        return true;
    }
    if((idx <=n && idx > 0) && load < k){
        return true;
    }
    return false;
}

int solve(int idx, long long mask, int cur_load){
    if (mask == limit) {
        return c[idx][0];
    }
       
    if(dp[idx][mask] != -1)
        return dp[idx][mask];

    int ret = MAXROAD;
    for (int i=0; i<=2*n; i++) 
    { 
        if ((mask & (1<<i)) == 0 && check(i, mask, cur_load)) 
        { 
            int load;
            if(i > n) load = cur_load - 1;
            else load = cur_load+1;
            int newMask = mask | (1<<i); 
            ret = min( ret, solve(i, newMask, load) + c[idx][i]); 
        } 
    } 
  
    // adding memoization and returning 
    return dp[idx][mask] = ret;
}

int main(){
    freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<2*n+1; i++){
        for(int j=0; j<2*n+1; j++){
            cin >> c[i][j];
        }
    }
    limit = (1<<(2*n+1)) - 1;
    memset(dp, -1, sizeof(dp));
    ans = solve(0, 1, 0);
    cout << ans << endl;
    return 0;
}