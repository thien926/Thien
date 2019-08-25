#include<iostream>
using namespace std;
typedef unsigned int ui;
typedef long long int ll;

void nhap(ui &n,ui &l,ui &r,ll *&a){
    cin>>n>>l>>r;
    a=new ll[n+1];
    for(ui i=1;i<=n;i++) cin>>a[i];
}

void xuat(ui n,ui l,ui r,ll *a){
    ll min=a[l],max=a[l];
    for(ui i=l;i<=r;i++){
        if(min>a[i]) min=a[i];
        if(max<a[i]) max=a[i];
    }
    cout<<min<<" "<<max<<endl;
}

int main(){
    ui n,l,r;
    ll *a;
    nhap(n,l,r,a);
    xuat(n,l,r,a);
    delete []a;
    return 0;
}
