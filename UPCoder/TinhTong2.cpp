#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
bool *b;

void nhap(){
    int x;
    while(cin >> x){
        a.push_back(x);
    }
    b = new bool[10];
    for(int i = 0; i < 10; i++) b[i] =false;
    b[2] = true;
    b [5]= true;
    b[3] = true;
    b[7] = true;
}

void xuly(){
    int n, k, s;
    for(int i = 0; i < a.size(); i++){
        n = a[i];
        s = 0;
        while(n > 0){
            k = n % 10;
            n = n / 10;
            if(b[k]) s = s + k;
        }
        cout << s <<endl;
    }
}

int main(){
    nhap();
    xuly();
    delete[]b;
    return 0;
}