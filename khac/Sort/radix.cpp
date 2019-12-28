#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int *a, *b, n;
int mmax = INT_MIN;

void nhap(){
    cout << "Nhap n: ";
    cin >> n;
    a = new int[n];
    b = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand()%50;
        if(mmax <= a[i]) mmax = a[i];
    }
}

void xuat(){
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl << endl;
}

void countsort(int exp){
    int i, c[10] = {0};
    for(i = 0; i < n; i++) c[(a[i]/exp)%10]++;
    for(i = 1; i < 10; i++) c[i] = c[i] + c[i-1];
    for(i = n-1; i >= 0; i--){
        b[c[(a[i]/exp)%10]-1] = a[i];
        --c[(a[i]/exp)%10];
    }
    for(i = 0; i < n; i++) a[i] = b[i];
}

void radixsort(){
    int i;
    for(i = 1; mmax/i > 0; i = i * 10) countsort(i);
}

int main(){
    nhap();
    xuat();
    radixsort();
    xuat();
    delete[] a;
    delete[] b;
    return 0;
}
