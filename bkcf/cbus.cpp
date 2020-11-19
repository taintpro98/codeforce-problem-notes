#include <bits/stdc++.h>
using namespace std;

#define MAXROAD 1000000000

int n, k;
long long ans = MAXROAD;
long long f = 0;
bool visited[30];
int x[30];
int c[30][30];
int load = 0;
int min_edge = MAXROAD;

bool check(int idx){
    if(visited[idx]){
        return false;
    }
    if(idx > n && visited[idx-n]){
        return true;
    }
    if(idx <=n && load < k){
        return true;
    }
    return false;
}

long long get_ans(){
    long long res = 0;
    for(int i=0; i<=2*n; i++){
        res += c[x[i]][x[(i+1)%(2*n+1)]];
    }
    return res;
}

void solve(int t){
    if(t<=2*n && f + (2*n+2 - t)*min_edge > ans) return;

    if(t > 2*n){
        ans = min(get_ans(), ans);
        return;
    }
    for(int v=1; v<=2*n; v++){
        if(check(v)){
            x[t] = v;
            f += c[x[t-1]][v]; 
            visited[v] = true;
            if(v > n) load--;
            else load++;
            solve(t+1);
            f -= c[x[t-1]][v];
            visited[v] = false;
            if(v > n) load++;
            else load--;
        }
    }
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<2*n+1; i++){
        for(int j=0; j<2*n+1; j++){
            cin >> c[i][j];
            if(c[i][j] > 0 && c[i][j] < min_edge) min_edge = c[i][j];
        }
    }
    // cout << min_edge << endl;
    solve(1);
    cout << ans << endl;
    return 0;
}