#include<iostream>
using namespace std;
typedef unsigned long long int ll;

void nhap(ll &n,bool *&was,int *&a){
    cin>>n;
    was=new bool[n+1];
    a=new int[n+1];
    for(ll i=0;i<=n;i++) was[i]=true;
}

void xuat(ll n,int *a){
    for(ll i=1;i<=n;i++) cout<<a[i];
    cout<<endl;
}

void backtracking(ll n,bool *was,ll j,int *a){
    for(ll i=1;i<=n;i++) if(was[i]){
        a[j]=i;
        was[i]=false;
        if(j==n) xuat(n,a);
        else backtracking(n,was,j+1,a);
        was[i]=true;
    }
}

int main(){
    ll n,k=1,i;
    bool *was;
    int *a;
    nhap(n,was,a);
    for(ll i=2;i<=n;i++) k=k*i;
    cout<<k<<endl;
    backtracking(n,was,1,a);
    delete []a;
    delete []was;
    return 0;
}
