#include <bits/stdc++.h>
using namespace std;

int n;
int c[23][23];
int ans = 1000;
bool visited[12];
int x[12];

int get_ans(){
    int res = 0;
    for(int i=0; i<=n; i++){
        res += c[x[i]][x[(i+1)%(n+1)]];
    }
    return res;
}

void solve(int k){
    // if(get_ans() > ans) return;
    if(k>n){
        ans = min(get_ans(), ans);
        return;
    }
    for(int v=1; v<=n; v++){
        if(!visited[v]){
            x[k] = v;
            visited[v] = true;
            solve(k+1);
            visited[v] = false;

        }
    }
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin >> c[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            c[i][j] = c[i][i+n] + c[i+n][j];
        }
    }
    solve(1);
    
    cout << ans << endl;

    return 0;
}