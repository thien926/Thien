#include <iostream>

using namespace std;
typedef unsigned long long int ll;

ll n;

void nhap(){
    cin >> n;
}

void solve(){
    if(n % 2 == 0 || n % 5 == 0) cout << "Có";
    else cout << "Không";
}

int main(){
    nhap();
    solve();
    return 0;
}
