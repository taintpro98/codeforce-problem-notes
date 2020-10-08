#include <bits/stdc++.h>
using namespace std;

int L, C, u;
const int N=1000;
typedef pair<int, int> ii;
vector<ii> rada1, rada2;
int cur[2*N][2*N];
int main(){
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> L >> C;
        rada1.clear(), rada2.clear();
        for(int i=1; i<=L; i++){
            for(int j=1; j<=C; j++){
                cin >> u;
                if(u) rada1.push_back(ii(i, j));
            }
        }
        for (int i=1; i<=L; i++){
            for(int j=1; j<=C; j++){
                cin >> u;
                if(u) rada2.push_back(ii(i, j));
            }
        }
        memset(cur, 0, sizeof(cur));
        for (auto a1: rada1){
            for(auto a2: rada2)
                cur[a1.first - a2.first + N][a1.second - a2.second + N]++;
        }
        int res = 0;
        for (int i=0; i<2*N; i++)
            for(int j=0; j<2*N; j++){
                res = max(res, cur[i][j]);
            }
        cout << res << endl;
    }
    
}