#include<iostream>
using namespace std;
typedef unsigned long long int ll;

int xuat(ll n){
   // if(n>=1&&n<=2) return 1;
    ll i,sum=0;
    for(i=0;i<=n;i++){
        sum=sum+i;
        if(n-sum==1) return 1;
        if (n <sum ) break;
    }
    return 0;
}

int main(){
    ll n;
    cin>>n;
    cout<<xuat(n);
    return 0;
}
