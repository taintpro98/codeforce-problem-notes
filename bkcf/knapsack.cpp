#include <bits/stdc++.h>
using namespace std;

const int N=31;
int n, b;
int wt[N], val[N], dp[N];

int knap(int t, int W){
    if(t==-1 || W <= 0) return 0;
    if(wt[t] > W) return knap(t-1, W);
    else return max(knap(t-1, W-wt[t]) + val[t], knap(t-1, W));
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> b;
    for (int i=0; i<n; i++){
        cin >> wt[i] >> val[i];
    }
    int res = knap(n-1, b);
    cout << res << endl;
    
    return 0;
}