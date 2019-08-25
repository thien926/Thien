#include<iostream>
#include<sstream>
using namespace std;

int main(){
    string a;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ostringstream convert;
        convert<<i;
        a=a+convert.str();
    }
    cout<<a[n-1];
    return 0;
}
