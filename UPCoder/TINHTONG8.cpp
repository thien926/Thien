#include <iostream>

using namespace std;
typedef unsigned long long int ll;
const ll k = 1e9;

double a, b;
ll a1, b1;

void nhap(){
    cin >> a >> b;
}

ll mod(ll n){
    return (n*(n+1))/2;
}

void solve(){
    a1 = (ll)a;
    b1 = (ll)b;
    if(a1 < a) a1 = (ll)a + 1;
    if(b1 > b) b1 = (ll)b - 1;
    ll res1, res2;
    res1 = mod(a1 - 1);
    res2 = mod(b1);
    cout << res2 - res1;
}

int main(){
    nhap();
    solve();
    return 0;
}
