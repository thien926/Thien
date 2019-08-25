#include<iostream>
using namespace std;

int main(){
    string a;
    cin>>a;
    if((a[0]-'0')+(a[1]-'0')==(a[2]-'0')*(a[3]-'0')) cout<<"yes";
    else cout<<"no";
    return 0;
}