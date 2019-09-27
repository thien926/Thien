#include <iostream>
#include <algorithm>

using namespace std;

int n, k, *a, res = 0;

void nhap(){
    cin >> n >> k;
    a = new int[n];
    int i;
    for(i = 0; i < n; i++) cin >> a[i];
}

int search(int l, int r, int x){
    if(l > r) return -1;
    int mid = (l+r)/2;
    if(x == a[mid]) return mid;
    if(x < a[mid]) return search(l, mid-1, x);
    return search(mid+1, r, x);
}

void solve(){
    sort(a+0, a+n);
    int i;
    for(i = 0; i < n; i++) if(search(0, n-1, a[i]+k) >= 0) res++;
    cout << res;
}

int main(){
    nhap();
    solve();
    delete []a;
    return 0;
}
