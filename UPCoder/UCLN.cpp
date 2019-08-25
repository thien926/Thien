#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long int ll;

ll ucln(ll a, ll b){
    if(a==0&&b==0) return 0;
    ll r;
    while(b!=0){
        r=a%b;a=b;b=r;
    }
    return a;
}

int main(){
    ll a,b;
    cin>>a>>b;
    a=abs(a);b=abs(b);
    cout<<ucln(a,b);
    return 0;
}
