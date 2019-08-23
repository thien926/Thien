#include<iostream>
#include<math.h>
using namespace std;
typedef unsigned long long int ll;

bool kt(ll n){
    if(n < 2) return false;
    ll x = sqrt(n);
    for(ll i = 2; i <= x; i++) if(n % i == 0) return false;
    return true;
}

int main(){
    ll n;
    cin >> n;
    if(kt(n)) cout << "true";
    else cout << "false";
    return 0;
}