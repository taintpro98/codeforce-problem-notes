#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int n;
int t[N];
int s[N];
int maxs[N];

int main(){
    freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s[i] >> t[i];
    }
    for(int i=1; i<=n; i++){
        maxs[t[i]] = t[i] - s[i];
    }
    for(int i=1; i<N; i++){
        maxs[i] = max(maxs[i-1], maxs[i]);
    }
    int ans = -1;
    for(int i=1; i<=n; i++){
        if(maxs[s[i]-1] > 0){
            ans = max(ans, maxs[s[i] - 1] + t[i] - s[i]);
        }
    }

    cout << ans << endl;
    return 0;
}