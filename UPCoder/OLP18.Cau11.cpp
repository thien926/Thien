#include<iostream>
using namespace std;
typedef long long int ll;

int n, m, *a;
ll mmax;

void nhap(){
	cin >> n >> m;
	a = new int [n];
	cin >> a[0];
	mmax = a [0];
	for(int i = 1; i < n; i++) cin >> a[i];
}

void xuly(){
	ll k;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int z = n - 1; z > j; z--){
				k = a[i] + a[j] + a[z];
				if(k <= m && mmax < k) mmax = k;
			}
		}
	}
}

int main(){
	nhap();
	xuly();
	cout<< mmax<<endl;
	delete []a;
	return 0;
}
