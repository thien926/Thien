#include<stdio.h>
typedef long long int ll;
void nhap(ll &n,ll *&a){
    scanf("%lld",&n);
    a=new ll[n];
    for(ll i=0;i<n;i++) scanf("%lld",&a[i]);
}
float tbc(ll n,ll *a){
    ll tong=0,d=0;
    for(ll i=0;i<n;i++) if(a[i]%2!=0){
        tong=tong+a[i];d++;
    }
//    double s=tong*1.0/d;
    return tong*1.0/d;
}
int main(){
    ll n,*a;
    nhap(n,a);
    printf("%10.2f",tbc(n,a));
    delete []a;
    return 0;
}
