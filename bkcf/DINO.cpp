#include <bits/stdc++.h>
using namespace std;

const int N=10e5+11;
int n, a[N];
string s;
queue<int> q;
stack<int> ans;

void print_ans(){
    while (!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
}

void solve(){
    for (int i = n - 1; i >= 0; i--) ans.push(a[i]);
    for (char c : s){
        if (c == 'H'){
            if (!q.empty()){
                ans.push(q.front());
                q.pop();
            }
        }
        if (c == 'C'){
            if (!ans.empty()){
                int v = ans.top();
                ans.pop();
                q.push(v);
            }
        }
    }
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;

    solve();
    print_ans();

    return 0;
}