#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
ifstream fi("INPUT.INP");
ofstream fo("OUTPUT.OUT");

int n;
vector<int> a;

void nhap(){
    fi >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) fi >> a[i];
    fi.close();
}

void heapify(int n, int i){
    int l, r, top;
    l = 2*i+1; r = 2*i+2; top = i;
    if(l < n && a[top] < a[l]) top = l;
    if(r < n && a[top] < a[r]) top = r;
    if(top != i){
        swap(a[i], a[top]);
        heapify(n, top);
    }
}

void heapsort(){
    int i;
    for(i = a.size()/2-1; i >= 0; i--) heapify(n, i);
    for(i = a.size()-1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(i, 0);
    }
}

void xuat(){
    for(int i = 0; i < a.size(); i++){
        fo << a[i] << " ";
        if((i+1) % 20 == 0) fo << endl;
    }
    fo.close();
}

int main(){
    nhap();
    heapsort();
    xuat();
    a.clear();
    return 0;
}
