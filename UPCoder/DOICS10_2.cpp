#include<iostream>
using namespace std;

void dequy(long n){
    if(n<=0) return;
    dequy(n/2);
    cout<<n%2;
}

int main(){
    long n;
    cin>>n;
    dequy(n);
    return 0;
}
