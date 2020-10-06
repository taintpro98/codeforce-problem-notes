#include <bits/stdc++.h>
using namespace std;
int n, b;
int a[200002];
int ml[200002], mr[200002];

int main(){
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> b;
    for (int i=1; i<=n; i++) cin >> a[i];
    ml[0] = mr[n] = -1;
    for (int i=1; i<=n; i++){
        ml[i] = ml[i-1] > a[i] ? ml[i-1]:a[i];
        mr[n+1-i] = mr[n+2-i] > a[n+1-i] ? mr[n+2-i]:a[n+1-i];
    }
    int M = 0;
    bool check = false;
    for (int i=2; i<n; i++){
        int x, y;
        x = ml[i-1] - a[i];
        y = mr[i+1] - a[i];
        if(x >=b && y>=b) check = true;
        M = M > (x+y) ? M:(x+y);
    }
    if (check) cout << M << endl;
    else cout << -1 << endl;
    return 0;
}