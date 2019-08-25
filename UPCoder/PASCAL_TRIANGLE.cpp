#include<iostream>
using namespace std;
typedef unsigned long long int ll;

void nhap(ll &n,ll **&a){
    cin>>n;
    a=new ll*[n];
    ll i,j;
    for(i=0;i<n;i++) a[i]=new ll[i+1];
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(j==0||j==i) a[i][j]=1;
            else{
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
    }
}

void xuat(ll n,ll **a){
    ll i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<n;i++) delete []a[i];
    delete []a;
}

int main(){
    ll n,**a;
    nhap(n,a);
    xuat(n,a);
    return 0;
}
