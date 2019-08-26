#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long int ll;

ll *a, res, mmin;
int n;

void set(){
    cin >> n;
    a = new ll[n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = a[i] + a[i-1];
    }
}

void solve(){
    res = a[n] - a[0];
    for(int i = 1; i <= n; i++){
        mmin = a[n] - a[i];
        mmin = a[i] - mmin;
        mmin = abs(mmin);
        if(res > mmin) res = mmin;
    }
    cout << res;
}

int main(){
    set();
    solve();
    delete []a;
    return 0;
}
