#include<iostream>
#include<queue>
using namespace std;

queue<int> p;

void nhap(){
    int x;
    while(cin >> x){
        p.push(x);
    }
}

void xuat(){
    while(!p.empty()){
        cout<< p.front() <<" ";
        p.pop();
    }
}

int main(){
    nhap();
    xuat();
    return 0;
}