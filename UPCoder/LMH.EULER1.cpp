#include<iostream>
using namespace std;
typedef unsigned long long int ll;

void nhap(ll &m,ll &n,ll **&a){
    cin>>m>>n;
    ll i;
    m=m+n-1;
    a=new ll*[n+1];
    for(i=0;i<=n;i++) a[i]=new ll[m+1];
}

ll sohoanvi(ll k,ll n,ll **a){
    ll i,j;
    for(i=0;i<=k;i++){
        for(j=0;j<=n;j++){
            if(i==0||i==j) a[i][j]=1;
            else{
                if(j<i) a[i][j]=0;
                else{
                    a[i][j]=a[i][j-1]+a[i-1][j-1];
                }
            }
        }
    }
    return a[k][n];
}

int main(){
    ll m,n,**a;
    nhap(m,n,a);
    cout<<sohoanvi(n,m,a);
    for(m=0;m<=n;m++) delete []a[m];
    delete []a;
    return 0;
}
