#include <bits/stdc++.h>
using namespace std;
string a, b;
string cal_sum(string a, string b){
    if (a.length() > b.length()) swap(a, b);
    string res = "";
    int n1 = a.length(), n2 = b.length();
    int carry = 0, sum; 
    for (int i=n2-1; i>=0; i--){
        if(i>n2-n1-1){
            sum = (a[i] - '0') + (b[i] - '0') + carry;
        }else {
            sum = (b[i] - '0') + carry;
        }
        res.push_back(sum%10 + '0');
        carry = sum/10;        
    }
    if(carry) res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    // freopen("in.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    string res = cal_sum(a, b);
    cout << res << endl;
    return 0;
    
}