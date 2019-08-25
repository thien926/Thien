#include<iostream>
using namespace std;
typedef long long int ll;

int **a, n;
ll **b, mmax = 0;

void nhap(){
    cin >> n;
    a = new int *[n + 1];
    b = new ll*[n + 1];
    for(int i = 1; i <= n; i++){
        a [i] = new int [i+1];
        b [i] = new ll[n+1];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    
}

ll max(int i, int j, ll **b){
    if(j == 1) return b[i-1][j];
    if(i == j) return b[i-1][j-1];
    if(b[i-1][j-1] > b[i-1][j]) return b[i-1][j-1];
    return b[i-1][j];
}

void xuly(){
    int i, j;
    for(i = 2; i <= n; i++){
        for(j = 1; j <= i ; j++) b[i][j] = b[i][j] + max(i, j, b);
    }
    for(i = 1; i <= n; i++) if(mmax < b[n][i]) mmax = b[n][i];
}

void xuat1(int i, int j){
    if(i == 1 && j == 1){
        cout<< a[i][j] <<" "; return;
    }
    if(j == 1){
        xuat1(i-1, j);
        cout<< a[i][j] <<" ";
        return;
    }
    if(j == i){
    	xuat1(i - 1, j-1);
    	cout<< a[i][j] <<" ";
    	return;
	}
    if(b[i-1][j-1] > b[i-1][j]) xuat1(i-1, j-1);
    else xuat1(i-1, j);
    cout<< a[i][j] <<" ";
}

void xuat(){
    cout << mmax <<endl;
    for(int i = 1; i <= n; i++){
        if(b[n][i] != mmax) continue;
        xuat1(n, i);
        cout<< endl;
    }
}

int main(){
    nhap();
    xuly();
/*    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= i ; j++) cout <<b[i][j] <<" ";
    	cout<<endl;
	}*/
    xuat();
    for(int i = 0; i <= n; i++){
        delete[]a[i];
        delete []b[i];
    }
    delete []a;
    delete []b;
    return 0;
}
