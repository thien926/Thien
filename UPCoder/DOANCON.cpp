#include<iostream>
using namespace std;
typedef unsigned int ui;
ui n,t,c,*a;
void nhap(){
    cin>>n>>t>>c;
    a=new ui[n];
    for(ui i=0;i<n;i++) cin>>a[i];
}
void xuat(){
    ui dem=0,i,k=0;
    for(i=0;i<n;i++) if(a[i]<=t) a[i]=1;
                     else a[i]=0;
    for(i=0;i<n;i++)
      if(a[i]){
          if(i-k+1==c) {
              dem++;k++;
          }
      }
      else{
          k=i+1;
      }
    cout<<dem;
}
int main(){
    nhap();
    xuat();
    delete []a;
    return 0;
}
