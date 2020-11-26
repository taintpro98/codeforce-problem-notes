#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
int W, H, n;
typedef pair<int, int> ii;
vector<ii> vec;
int ans;
int dp[700][700];
int min_w = INF, min_h = INF;

bool cmp(ii a, ii b){
    if(a.first != b.first) return false;
    if(a.second != b.second) return false;
    return true;
}

bool check(int i, int j){
    for(ii v: vec){
        if(cmp(v, ii(i, j))){
            return true;
        } 
    }
    return false;
}

int solve(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if((i < min_w) || (j < min_h)){
        return dp[i][j] = i*j;
    } 
    if(check(i, j)) return dp[i][j] = 0;
    int res = i*j;

    for(int v=1; v<i; v++){
        res = min(res, solve(v, j) + solve(i-v, j));
    }
    for(int v=1; v<j; v++){
        res = min(res, solve(i, v) + solve(i, j-v));
    }
    return dp[i][j] = res;
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> W >> H >> n;
    for(int i=0; i<n; i++){
        int w, h; cin >> w >> h;
        min_w = min(min_w, w);
        min_h = min(min_h, h);
        vec.push_back(ii(w, h));
    }
    memset(dp, -1, sizeof(dp)); 

    ans = solve(W, H);
    cout << ans << endl;
    return 0;
}