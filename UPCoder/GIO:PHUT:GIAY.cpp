#include<iostream>
using namespace std;
typedef unsigned long long int ll;

int main(){
    ll n;
    cin>>n;
    cout<<n/3600<<":";
    n=n%3600;
    cout<<n/60<<":";
    n=n%60;
    cout<<n;
    return 0;
}
