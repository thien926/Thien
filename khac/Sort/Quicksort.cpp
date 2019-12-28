#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int *a, n = 0;

void nhap(){
    cout << "Nhap n: ";
    cin >> n;
    a = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand()%100-50;
    }
}

void xuat(){
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl << endl;
}

void quicksort(int l, int r){
    int i = l, j = r, x = a[(l+r)/2];
    do{
        while(a[i] < x) ++i;
        while(a[j] > x) --j;
        if(i <= j) swap(a[i++], a[j--]);
    }
    while(i < j);
    if(l < j) quicksort(l, j);
    if(i < r) quicksort(i, r);
}

int main(){
    nhap();
    xuat();
    quicksort(0, n-1);
    xuat();
    delete[] a;
    return 0;
}
