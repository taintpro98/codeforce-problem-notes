#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int n;

void print_ans(int idx, int a){
    cout << "Case " << idx << ": maximum height = " << a << endl;
}

pii f(int u, int v){
    return {min(u,v), max(u,v)};
}

bool check(pii base_u, pii base_v){
    return base_u.first < base_v.first && base_u.second < base_v.second;
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int num = 1;
    while(n){
        int ans=0;

        map<pii, int> dp;
        map<pii, int> h;

        for(int i=0; i<n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            dp[f(x,y)] = max(z, dp[f(x,y)]);
            dp[f(y,z)] = max(x, dp[f(y,z)]);
            dp[f(z,x)] = max(y, dp[f(z,x)]);
            h[f(x,y)] = max(z, dp[f(x,y)]);
            h[f(y,z)] = max(x, dp[f(y,z)]);
            h[f(z,x)] = max(y, dp[f(z,x)]);
        }
        for(int i=0; i<90; i++){
            for(auto u: dp){
                for(auto v: dp){
                    if(check(u.first, v.first)){
                        dp[u.first] = max(dp[u.first], dp[v.first] + h[u.first]);
                    }
                }
            }
        }
        for(auto u: dp) ans = max(ans, dp[u.first]);
        print_ans(num, ans);
        cin >> n;
        num++;
    }

    return 0;
}