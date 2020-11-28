#include <bits/stdc++.h>
using namespace std;

const int N=10e5+2;
int n;
int a[N];

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int cnt = 1;
    int x = a[1];
    for(int i=2; i<=n; i++){
        if(a[i] <= x){
            cnt++;

        }
        x = a[i];
    }
    cout << cnt << endl;

    return 0;
}