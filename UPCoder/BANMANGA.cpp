#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

struct arr{
    long n;
    long mn;
};

int T, n, k, res = 0;
int **a;
arr *b;
stack<int> sr,sl;

void nhap(){
    int i, j;
    cin >> T;
    b = new arr[T];
    a = new int*[T];
    for(i = 0; i < T; i++){
        cin >> b[i].n >> b[i].mn;
        a[i] = new int[b[i].n];
        for(j = 0; j < b[i].n; j++) cin >> a[i][j];
    }
}

void exch(int &a, int &b){
    int r = a;
    a = b;
    b = r;
}

void quicksort(int ii, int left, int right){
    sl.push(left);
    sr.push(right);
    int x, l, r, i, j;
    while(!sl.empty()){
        l = sl.top(); sl.pop();
        r = sr.top(); sr.pop();
        x = a[ii][(l+r)/2];
        i = l; j = r;
        do{
            while(x > a[ii][i]) i++;
            while(x < a[ii][j]) j--;
            if(i <= j) exch(a[ii][i++], a[ii][j--]);
        }
        while(i < j);
        if(l < j){
            sl.push(l);
            sr.push(j);
        }
        if(i < r){
            sl.push(i);
            sr.push(r);
        }
    }
}

void solve(){
    long i, j, d = 0, res, resum;
    for(i = 0; i < T; i++){
        quicksort(i, 0, b[i].n-1);
        d = 0;
        resum = 0;
        for(j = 0; j < b[i].n - 1; j++) if(a[i][j] == a[i][j+1] - 1){
            d++;
        }
        else if(d > 0){
            ++d;
            res = sqrt(2*d-1);
            while(!((res*(res-1)/2 + 1) <= d && (res*(res+1)/2 >= d))){
                res++;
            }
            resum = resum +(res-1)*b[i].mn;
            d = 0;
        }
        if(d > 0){
            ++d;
            res = sqrt(2*d-1);
            while(!((res*(res-1)/2 + 1) <= d && (res*(res+1)/2 >= d))){
                res++;
            }
            resum = resum +(res-1)*b[i].mn;
        }
        cout << b[i].n*b[i].mn + resum << endl;
    }
}

int main(){
    nhap();
    solve();
    for(int i = 0; i < T; i++) delete []a[i];
    delete []a;
    delete []b;
    return 0;
}
