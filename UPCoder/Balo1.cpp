#include<iostream>
using namespace std;
typedef unsigned int ui;
void nhap(ui &n,ui &k,ui *&a,ui **&b){
    cin>>k>>n;
    a=new ui[k+1];
    b=new ui*[k+1];b[0]=new ui[n+1];
    for(ui i=1;i<=k;i++){
        cin>>a[i];b[i]=new ui[n+1];
    }
}
void taobang(ui n,ui k,ui *a,ui **b){
    for(ui i=0;i<=k;i++){
        for(ui j=0;j<=n;j++){
            if(i==0||j==0) b[i][j]=0;
            else{
                if(a[i]>j) b[i][j]=b[i-1][j];
                else{
                    b[i][j]=b[i-1][j];
                    if(b[i][j]<a[i]+b[i-1][j-a[i]]) b[i][j]=a[i]+b[i-1][j-a[i]];
                }
            }
        }
    }
}
void xuat(ui i,ui j,ui *a,ui **b){
    if(i<=0||j<=0) return;
    while(b[i][j]==b[i-1][j]) i--;
    xuat(i-1,j-a[i],a,b);
    cout<<i-1<<" ";
}
int main(){
    ui n,k,*a,**b;
    nhap(n,k,a,b);
    taobang(n,k,a,b);
/*    for(ui i=0;i<=k;i++){
    	for(ui j=0;j<=n;j++) cout<<b[i][j]<<"\t";
    	cout<<endl;
	}*/
    cout<<b[k][n]<<endl;
    xuat(k,n,a,b);
    for(ui i=0;i<=k;i++) delete []b[i];
    delete []a;delete []b;
    return 0;
}
