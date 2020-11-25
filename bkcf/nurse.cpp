#include <bits/stdc++.h>
using namespace std;

const int M=10e9+7;
const int N=1002;
int K1, K2;
int n;
int dp[N];
int ans;

int solve(int i){
    if(i == 0) return dp[i] = 1;
    if(i == 1) return dp[i] = 1;
    if(i<K1+1) return dp[i] = 0;
    if(i==K1+1) return dp[i] = 1;
    int res = 0;
    for(int j=max(i-K2-1, 0); j<=i-K1-1; j++){
        res += solve(j);
        res %= M;
    }
    return dp[i] = res;
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> K1 >> K2;
    ans = solve(n+1) + solve(n);
    cout << ans << endl;

    return 0;
}