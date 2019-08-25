#include<iostream>
using namespace std;
typedef long long int ll;
void nhap(ll &n,ll &x,ll *&a){
    cin>>n>>x;
    a=new ll[n];
    for(ll i=0;i<n;i++) cin>>a[i];
}
void xuat(ll n,ll x,ll *a){
    ll i;
    for(i=n-1;i>=0;i--) if(a[i]==x){
        cout<<"Y\n"<<i;return;
    }
    cout<<"N\n";
    for(i=0;i<n;i++) if(x<a[i]){
        cout<<i;return;
    }
    cout<<-1;
}
int main(){
    ll n,x,*a;
    nhap(n,x,a);
    xuat(n,x,a);
    delete []a;
    return 0;
}
