#include <iostream>
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

void merge(int l, int m, int r, int L[], int R[]){
    int i, j, k;
    int n1 = m-l+1, n2 = r-m;
    //tạo 2 mảng
    for(i = 0; i < n1; i++) L[i] = a[l+i];
    for(i = 0; i < n2; i++) R[i] = a[m+1+i]; 
    //sắp xếp
    i = j = 0;
    k = l;
    while(i < n1 && j < n1){
        if(L[i] <= R[j]){
            a[k] = L[i++];
        }
        else{
            a[k] = R[j++];
        }
        k++;
    }

    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void mergesort(int l, int r,int L[], int R[]){
    if(l < r){
        int m = (l+r)/2;
        mergesort(l, m, L, R);
        mergesort(m+1, r, L, R);
        merge(l, m, r, L, R);
    }
}

void xuat(){
    for(int i = 0; i < a.size(); i++){
        fo << a[i] << " ";
        if((i+1)%20 == 0) fo << endl;
    }
    fo.close();
}

int main(){
    nhap();
    int L[a.size()/2+1], R[a.size()/2+1];
    mergesort(0, a.size()-1, L, R);
    xuat();
    return 0;
}
