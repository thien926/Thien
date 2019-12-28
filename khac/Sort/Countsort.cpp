#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int *a, *b, n = 0;
int mmin = INT_MAX, mmax = INT_MIN;

void nhap(){
    cout << "Nhap n: ";
    cin >> n;
    a = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand()%50+1;
        if(a[i] <= mmin) mmin = a[i];
        if(a[i] >= mmax) mmax = a[i];
    }
}

void solve(){
    int n1 = mmax - mmin + 1, i = 0, j = 0;
    b = new int[n1];
    for(i = 0; i < n1; i++) b[i] = 0;
    for(i = 0; i < n; i++){
        b[a[i]-mmin]++;
    }
    for(i = 0; i < n1; i++) if(b[i] > 0) {
        while(b[i] > 0){
            a[j++] = i+mmin;
            b[i]--;
        }
    }
}

void xuat(){
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl << endl;
}

int main(){
    nhap();
    xuat();
    solve();
    xuat();
    delete[] a;
    delete[] b;
    return 0;
}
