#include<iostream>
#include<sstream>
using namespace std;
typedef unsigned long long int ll;

string nhap(ll &n, ll &m, string a){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ostringstream convert;
        convert<<i;
        a=a+convert.str();
    }
    m--;
    return a;
}

void xuly(string a, ll n, ll m){
    ll k=0;
    while(a.length()>0){
        k=k+m;
        if(k>a.length()) k=k%a.length();
        cout<<a[k]<<" ";
        a.erase(k,1);
    }
}

int main(){
    string a;
    ll n,m;
    a=nhap(n,m,a);
    xuly(a,n,m);
    return 0;
}