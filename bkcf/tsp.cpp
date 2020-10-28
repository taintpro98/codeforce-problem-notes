#include <bits/stdc++.h>
using namespace std;
int n, m;
int position = 1;
int matrix[21][21];
int x[21];
int MIN = 1000000;
bool status[21];
int sum = 0;

bool check(int v, int k){
    if (k==n-1) return !status[v] && matrix[x[(k-1)%n]][v] > 0 && matrix[v][1] > 0;
    return !status[v] && matrix[x[(k-1)%n]][v] > 0;
}

// int solution(){
//     int res = 0;
//     for(int i=0; i<n; i++){
//         res += matrix[x[i%n]][x[(i+1)%n]];
//     }
//     return res;
// }

void TRY(int k){
    for(int v=2; v<=n; v++){
        if(check(v,k)){
            x[k] = v;
            sum += matrix[x[(k-1)%n]][v];
            status[v] = true;
            if(k == n-1) {
                sum += matrix[v][1];
                MIN = min(MIN, sum);
            } else{
                TRY(k+1);
            }
            status[v] = false;
            sum -= matrix[x[(k-1)%n]][v];
            if(k == n-1) sum -= matrix[v][1];
        }
    }
}

int main(){
    // freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int t=1; t<=m; t++){
        int i, j, c;
        cin >> i >> j >> c;
        matrix[i][j] = c;
    }
    x[0] = 1;
    status[0] = true;
    TRY(1);
    cout << MIN << endl;

    return 0;
}