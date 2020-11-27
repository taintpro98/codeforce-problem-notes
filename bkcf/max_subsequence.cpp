#include <bits/stdc++.h>
using namespace std;

const int N=10e6+1;
int n;
int a[N];
int sum = 0;
int ans = 0;

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        int tmp; cin >> tmp;
        sum += tmp;
        if(sum < 0) sum = 0;
        ans = max(sum, ans);
    }
    cout << ans << endl;

    return 0;
}