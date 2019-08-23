#include<iostream>
#include<math.h>
using namespace std;
typedef unsigned long long int ll;

bool kt(ll n){
    if(sqrt(n) == (ll)sqrt(n)) return true;
    else return false;
}

int main(){
    ll n;
    cin >> n;
    if(kt(n)) cout << "yes";
    else cout << "no";
    return 0;
}