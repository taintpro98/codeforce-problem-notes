#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> list[11];

int main(){
    freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i=0; i<m; i++){
        int k;
        cin >> k;
        for(int j=0; j<k; j++){
            int t; cin >> t;
            list[i].append(t);
        }
    }
    int k; cin >> k;
    

}
