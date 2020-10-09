#include <bits/stdc++.h>
using namespace std;

typedef struct customer
{
	long x, m, r;	
};

bool cmp(customer a, customer b)
{
	return a.x < b.x;
}

int n;
long k;
customer a[1002];

long cal(int left, int right){
    
}

int main(){
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i].x >> a[i].m;
    sort(a+1, a+n+1, cmp);
    long dist = 0;
    int pivot = 1001; // first place that x[pivot] > 0
    for (int i=1; i<=n; i++){
        long q = a[i].m/k;
        a[i].r = a[i].m%k;
        if(a[i-1].x <= 0 && a[i].x > 0) pivot = i;
        dist += 2*q*abs(a[i].x);
    }
    

    return 0;
}