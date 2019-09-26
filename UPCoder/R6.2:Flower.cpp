#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned long long int ll;

int n, *a, *b;
ll sum1 = 0, sum2 = 0, res = 0;

void nhap(){
    cin >> n;
    a = new int[n];
    b = new int[n];
    int i;
    for(i = 0; i < n; i++){
        cin >> a[i];
        sum1 = sum1 + a[i];
    }
    for(i = 0; i < n; i++){
        cin >> b[i];
        sum2 = sum2 + b[i];
    }
}

bool Compare(int a, int b, int k){
    switch(k){
        case 1: return a < b; break;
        case -1: return a > b; break;
    }
    return false;
}

void quicksort(int l, int r, int *rr, int k){
    int x = rr[(l+r)/2], i = l, j = r;
    do{
        while(Compare(rr[i], x, k)) i++;
        while(Compare(x, rr[j], k)) j--;
        if(i <= j) swap(rr[i++], rr[j--]);
    }
    while(i < j);
    if(l < j) quicksort(l, j, rr, k);
    if(i < r) quicksort(i, r, rr, k);
}

void solve(){
    quicksort(0, n-1, a, -1);
    quicksort(0, n-1, b, 1);
    for(int i = 0; i < n; i++) if(sum1 > sum2){
        sum1 = sum1 - a[i] + b[i];
        sum2 = sum2 -b[i] + a[i];
        res++;
    }
    else break;
    cout << res;
}

int main(){
    nhap();
    solve();
    delete []a;
    delete []b;
    return 0;
}
