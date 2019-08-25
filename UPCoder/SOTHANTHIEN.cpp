#include<iostream>
using namespace std;
typedef unsigned long long int ll;

ll sob(ll a){
    ll k=0;
    while(a>0){
        k = k * 10 + a % 10; 
        a = a / 10;
    }
    return k;
}

ll ucln(ll a, ll b){
    if(a==0 && b==0) return 0;
    ll r;
    while( b != 0 ){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    ll a,b;
    cin>>a;
    b=sob(a);
    if(ucln(a,b)==1) cout<< "YES";
    else cout<< "NO";
    return 0;
}
