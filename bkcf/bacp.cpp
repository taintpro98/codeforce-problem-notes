#include <bits/stdc++.h>
using namespace std;

#define INF 1000;
int n, m;
int credit[18];
int A[18][18];
int load[6];
int front[18];
int behind[18];
int assign[18];
int ans;

bool cmp(int p, int q){
    return load[p] < load[q];
}

int get_ans(){
    return *max_element(load + 1, load + m + 1);
}

int handle(int t){
    int res = 1;
    for(int i=1; i<=n; i++){
        if(A[i][t] == 1){
            res = max(handle(i) + 1, res);
        }
    }
    return front[t] = res;
}

int process(int t){
    int res = m;
    for(int i=1; i<=n; i++){
        if(A[t][i] == 1){
            res = min(process(i) - 1, res);
        }
    }
    return behind[t] = res;
}

void solve(int t){
    
    if(get_ans() >= ans) return;
    if(t > n){
        ans = min(get_ans(), ans);
        return;
    }
    vector<int> index;
    int begin = front[t];
    for(int i=1; i<=n; i++){
        if(A[i][t] == 1 && assign[i] > 0){
            begin = max(assign[i] + 1, begin);
        }
    }
    int end = behind[t];
    for(int i=1; i<=n; i++){
        if(A[t][i] == 1 && assign[i] > 0){
            end = min(assign[i] - 1, end);
        }
    }

    for(int p=begin; p<=end; p++){
        index.push_back(p);
    }
    sort(index.begin(), index.end(), cmp);
    for(int p : index){
        assign[t] = p;
        load[p] += credit[t];
        solve(t+1);
        assign[t] = 0;
        load[p] -= credit[t];
    }
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> credit[i];
    }
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> A[i][j]; 
        }
    }
    for(int i=1; i<=n; i++){
        front[i] = 1;
        behind[i] = m;
    }
    handle(1);
    process(1);
    
    ans = INF;
    solve(1);
    cout << ans << endl;
}