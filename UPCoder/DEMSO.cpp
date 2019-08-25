#include<iostream>
using namespace std;
typedef unsigned long long int ll;
typedef unsigned short int usi;
void nhap(ll &m,ll &n,ll **&a,usi *&b){
    cin>>m>>n;
    a=new ll*[m];
    b=new usi[10];
    ll i,j;
    for(i=0;i<m;i++) a[i]=new ll[n];
    for(i=0;i<m;i++) for(j=0;j<n;j++) cin>>a[i][j];
    for(i=0;i<10;i++) b[i]=0;
}
void dem(ll n,usi *b){
    while(n>0){
        b[n%10]++;
        n/=10;
    }
}
void xuat(ll **a,ll m,ll n,usi *b){
    ll i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            dem(a[i][j],b);
        }
    }
    for(i=0;i<10;i++) if(b[i]!=0){
        cout<<i<<" : "<<b[i]<<endl;
    }
}
int main(){
    ll **a,m,n;
    usi *b;
    nhap(m,n,a,b);
    xuat(a,m,n,b);
    delete []b;
    for(n=0;n<m;n++) delete []a[n];
    delete []a;
    return 0;
}
