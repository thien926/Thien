#include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    ll max=-9223372036854775807,k;
    while(cin>>k){
        if(k>max) max=k;
    }
    cout<<max;
    return 0;
}
