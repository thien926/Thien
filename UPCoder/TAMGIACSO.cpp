#include<iostream>
using namespace std;
typedef unsigned long long int ll;
typedef unsigned int ui;
void nhap(ll &n,ll **&a,ll **&b){
	cin>>n;
	a=new ll*[n];b=new ll*[n];
	ll i,j;
	for(i=0;i<n;i++){
		a[i]=new ll[i+1];
		b[i]=new ll[i+1];
	}
	for(i=0;i<n;i++)
	  for(j=0;j<=i;j++) cin>>a[i][j];
	b[0][0]=a[0][0];
}
ll max1(ll i,ll j,ll **a,ll **b){
	if(j==0) return a[i][j]+b[i-1][j];
	if(i==j) return a[i][j]+b[i-1][j-1];
	if(b[i-1][j-1]+a[i][j]>b[i-1][j]+a[i][j]) return a[i][j]+b[i-1][j-1];
		else return a[i][j]+b[i-1][j];
}
void tao(ll n,ll **a,ll **b,ll &p,ll &q){
	ll i,j,max,k;
	for(i=1;i<n;i++){
		for(j=0;j<=i;j++) b[i][j]=max1(i,j,a,b);
	}
	max=b[n-1][0];i=n-1;j=0;
	for(k=1;k<n;k++) if(max<b[i][k]){
		max=b[i][k];
		j=k;
	}
	p=i;q=j;
}
void xuat(ll **a,ll **b,ll i,ll j){
	if(i==0&&j==0){
		cout<<a[i][j]<<" ";return;
	}
	if(j==0){
		xuat(a,b,i-1,j);
		cout<<a[i][j]<<" ";return;
	}
	if(i-1<j){
		xuat(a,b,i-1,j-1);cout<<a[i][j]<<" ";return;
	}
	if(b[i-1][j-1]>b[i-1][j]){
		xuat(a,b,i-1,j-1);cout<<a[i][j]<<" ";
	}
	else{
		xuat(a,b,i-1,j);cout<<a[i][j]<<" ";
	}
}
int main(){
	ll n,**a,**b,i,j;
	nhap(n,a,b);
	tao(n,a,b,i,j);
	xuat(a,b,i,j);
	cout<<endl<<b[i][j]<<endl;
	for(ll i=0;i<n;i++){
		delete []a[i];delete []b[i];
	}
	delete []a;delete []b;
	return 0;
}
