#include <bits/stdc++.h>
using namespace std;
const int N = 1000002;
long long h[N];
long long n;
stack<long long> S;
long long L[N],R[N] ;
int main(){
    
    // freopen("in.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        for(int i = 1; i <= n; i++) cin >> h[i];
        unsigned long long ans = 0;
        h[0] = -1;
        h[n+1] = -1;
        for(int i = 1; i <= n+1; i++){
            while(!S.empty() && h[S.top()] > h[i]){
                R[S.top()] = i; S.pop();
            }
            S.push(i);
        }

        for(int i = n; i >= 0; i--){
            while(!S.empty() && h[S.top()] > h[i]){
                L[S.top()] = i; S.pop();
            }
            S.push(i);
        }
        for(int i = 1; i<= n; i++){
            long long S = (R[i] - L[i] - 1)* h[i];
            ans = S > ans ? S: ans;
        }
        cout << ans << endl;
    }
}
