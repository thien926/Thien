#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

int n;
ll *a;

void nhap(){
    cin >> n;
    a = new ll[n];
    for(int i = 0; i < n; i ++) cin >> a [i];
}

void quicksort(int l, int r){
    ll x = a [(l+r)/2];
    int i = l, j = r;
    do{
        while(a [i] < x) i++;
        while(a [j] > x) j--;
        if(i <= j) swap(a [i++], a [j--]);
    }
    while(i < j);
    if(l < j) quicksort(l, j);
    if(i < r) quicksort(i, r);
}

int main(){
    nhap();
    quicksort(0, n-1);
    if(a [0]*a [1]*a [n-1] >a [n-1]*a [n-2]*a [n-3]){
        cout<<a [0] << " " << a [1] << " " <<a [n-1];
    }
    else{
        cout<<a [n-3] << " " <<a [n-2] << " " << a [n-1];
    }
    delete []a;
    return 0;
}
