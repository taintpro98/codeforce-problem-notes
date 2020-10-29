#include <bits/stdc++.h>
using namespace std;

#define MAXMASK 2097152
#define MAXROAD 1000001
int n, m;
int matrix[21][21];
long long limit;
int dp[22][MAXMASK];

int solve(int idx, long long mask){
    if (mask == limit) 
    //    return matrix[idx][1] + dp[idx][mask];
       return matrix[idx][1];
    if(dp[idx][mask] != -1)
        return dp[idx][mask];
    int ret = MAXROAD;

    for (int i=0; i<n; i++) 
    { 
        if ((mask & (1<<i)) == 0) 
        { 
            int newMask = mask | (1<<i); 
            ret = min( ret, solve(i+1, newMask) + matrix[idx][i+1]); 
        } 
    } 
  
    // adding memoization and returning 
    return dp[idx][mask] = ret; 
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(matrix, MAXROAD, sizeof(matrix)); 
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            matrix[i][j] = MAXROAD;
        }
    }
    for (int t=1; t<=m; t++){
        int i, j, c;
        cin >> i >> j >> c;
        matrix[i][j] = c;
    }
    limit = (1<<n) - 1;
    memset(dp, -1, sizeof(dp)); 
    int ans = solve(1, 1);
    cout << ans << endl;
}