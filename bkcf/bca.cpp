#include <bits/stdc++.h>
using namespace std;

#define INF 100;
int m, n;
int load[11];
bool teach[11][31];
bool ban[11][31];
bool conflict[31][31];
int ans;

int get_ans(){
    return *max_element(load + 1, load + n + 1);
}

bool cmp(int p, int q) {return load[p] < load[q];}

void solve(int t){
    if(get_ans() >= ans) return;
    
    if(t > n){
        ans = min(get_ans(), ans);
        return;
    }

    vector<int> teachers;
    for(int i=1; i<=m; i++){
        if(teach[i][t] && !ban[i][t]) teachers.push_back(i);
    }
    sort(teachers.begin(), teachers.end(), cmp);
    for(int v : teachers){
        for(int i=t+1; i<=n; i++){
            if(conflict[t][i]) ban[v][i]=true;
        }
        load[v]++;
        solve(t+1);
        load[v]--;
        for(int i=t+1; i<=n; i++){
            if(conflict[t][i]) ban[v][i]=false;
        }
    }
}

int main(){
    freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i=1; i<=m; i++){
        int k;
        cin >> k;
        while(k--){
            int t; cin >> t;
            teach[i][t] = true;
        }
    }
    int k; cin >> k;
    while(k--){
        int c1, c2; cin >> c1 >> c2;
        if(c1 > c2) swap(c1, c2);
        conflict[c1][c2] = true;
    }
    ans = INF;
    solve(1);
    cout << ans << endl;

}
