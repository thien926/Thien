#include<iostream>
using namespace std;
typedef unsigned long long int ll;

bool kt(ll n){
    ll k = 0, x = n /2;
    for(ll i = 1; i <= x; i++) if(n % i == 0) k = k + i;
    if(k == n) return true;
    return false;
}

int main(){
    ll n;
    cin >> n;
    if(kt(n)) cout<<"Yes";
    else cout<<"No";
    return 0;
}