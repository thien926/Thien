#include<iostream>
using namespace std;
typedef unsigned long long int ll;
int main(){
    ll f1=1,f2=1,f3,n,d=2;
    cin>>n;
    if(n==1) cout<<f1;
    else{
        if(n==2) cout<<f1<<" "<<f2;
        else{
            cout<<f1<<" "<<f2<<" ";
            do{
                f3=f1+f2;
                d++;
                cout<<f3<<" ";
                f1=f2;f2=f3;
            }
            while(d<n);
        }
    }
    return 0;
}
