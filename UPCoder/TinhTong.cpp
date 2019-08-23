#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long int ll;

int main(){
    ll k,sum;
    while(cin>>k){
        k=abs(k); sum=0;
        while(k>0){
            sum=sum+k%10; k/=10;
        }
        cout<<sum<<endl;
    }
    return 0;
}