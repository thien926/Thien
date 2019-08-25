#include<iostream>
using namespace std;
typedef long long int ll;
const ll max1=922337203685477580;
const ll min1=-922337203685477580;

int main(){
    ll k,max=min1,min=max1;
    while(cin>>k){
        if(k>max) max=k;
        if(k<min) min=k;
    }
    cout<<min<<"\n"<<max<<"\n"<<max+min;
    return 0;
}
