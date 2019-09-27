#include <iostream>

using namespace std;

int n, *a;

void nhap(){
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
}

void solve(){
    int chan = 0, le = 0, i, c, b;
    for(i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            chan++;
            b = i;
        }
        else{
            le++;
            c = i;
        }
    }
    if(le == 1) cout << c+1;
    else cout << b+1;
}

int main(){
    nhap();
    solve();
    delete []a;
    return 0;
}
