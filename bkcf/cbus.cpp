#include <bits/stdc++.h>
using namespace std;

int n, k;
int cost[23][23];

int main(){
    freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<2n+1; i++){
        for(int j=0; j<2n+1; j++){
            cin >> cost[i][j];
        }
    }
    
}