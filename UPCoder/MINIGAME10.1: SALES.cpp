#include <iostream>

using namespace std;

int n, m, *a, res = 0;

void nhap(){
    cin >> n >> m;
    a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
}

void qusort(int l, int r){
    int x = a[(l+r)/2], i = l, j = r;
    do{
        while(a[i] < x) i++;
        while(x < a[j]) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    while(i < j);
    if(l < j) qusort(l, j);
    if(i < r) qusort(i, r);
}

void solve(){
    qusort(0, n-1);
    int i;
    for(i = 0; i < m; i++) if(a[i] < 0) res = res - a[i];
    cout << res;
}

int main(){
    nhap();
    solve();
    delete []a;
    return 0;
}
