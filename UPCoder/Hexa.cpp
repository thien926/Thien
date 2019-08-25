#include<iostream>
using namespace std;
typedef unsigned int ui;
void dequy(ui n){
    if(n<1) return;
    ui x=n%16;
    dequy(n/16);
    if(x<10) cout<<x;
    else{
        switch(x){
            case 10:cout<<"A";break;
            case 11:cout<<"B";break;
            case 12:cout<<"C";break;
            case 13:cout<<"D";break;
            case 14:cout<<"E";break;
            case 15:cout<<"F";break;
        }
    }
}
int main(){
    ui n;
    cin>>n;
    dequy(n);
    return 0;
}