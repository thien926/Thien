#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

int n, k;
ll *a, res = 0;

void nhap(){
    cin >> n >> k;
    a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
}

void qusort(int l, int r){
    ll x = a[(l+r)/2];
    int i = l, j = r;
    do{
        while(a[i] > x) i++;
        while(x > a[j]) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    while(i < j);
    if(l < j) qusort(l, j);
    if(i < r) qusort(i, r);
}

void solve(){
    qusort(1, n-1);
    res = res + a[0];
    int i;
    for(i = 1; i < n; i++) if(i <= k) res = res + a[i];
    else res = res - a[i];
    cout << res;
}

int main(){
    nhap();
    solve();
    delete []a;
    return 0;
}
