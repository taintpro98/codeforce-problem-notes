#include <bits/stdc++.h>
using namespace std;
int n;
long k, x[1002], m[1002];


int main(){
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> x[i] >> m[i];
    sort(x, x+n);

    return 0;
}