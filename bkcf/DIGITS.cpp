#include <bits/stdc++.h>
using namespace std;

vector<int> convert_numer2digits(int n){
    vector<int> res;
    while(n){
        int tmp;
        tmp = n%10;
        res.push_back(tmp);
        n/=10;
    }
    return res;
}

bool check(int hust, int soict){
    if(soict > 99999 || soict < 10000) return false;
    vector<int> x = convert_numer2digits(hust);
    vector<int> y = convert_numer2digits(soict);

    if(x[0] != y[0]) return false;
    if(x[1] != y[4]) return false;
    
    set<int> Y;
    for(auto u: x) Y.insert(u);
    for(auto u: y) Y.insert(u);
    
    if(Y.size() != 7) return false;
    return true;
}

int main(){
    freopen("bkcf/in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = 0;
        int hust, soict;
        for(int hust=1000; hust<=9999; hust++){
            soict = n - hust;
            if(check(hust, soict)) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}