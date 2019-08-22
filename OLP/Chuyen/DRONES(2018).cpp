#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct Toado{
    long long int info;
    int i;
};

Toado *a;
int n;

void nhap(){
    cin >> n;
    long long int q;
    a = new Toado[n+1];
    long long int u, v;
    for(int i = 1; i <= n; i++){
        cin >> u >> v;
        u = abs(u);
        v = abs(v);
        q = (u > v) ? u : v;
        a[i].i = i;
        a[i].info = q;
    }
}

bool compare1(Toado a, Toado b){
	return a.info < b.info;
}

bool compare2(Toado a, Toado b){
	return a.i < b.i;
}

void solve(){
    int i, j;
    sort(a+1, a+n+1, compare1);
    for(i = 1; i <= n; i++){
        for(j = i+1; j <= n; j++) if(a[i].info != a[j].info) break;
        sort(a+i, a+j, compare2);
        i = j - 1;

    }

    for(i = 1; i <= n; i++){
    	if(i > a[i].info){
	    	cout << -1;
	    	return;
	    }
    }
    for(i = 1; i <= n; i++) cout << a[i].i << " ";
}

int main(){
    nhap();
    solve();
    delete []a;
    return 0;
}
