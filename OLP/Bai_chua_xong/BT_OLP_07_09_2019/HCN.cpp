#include <iostream>
#include <fstream>

using namespace std;
typedef long long int ll;
ifstream fi("HCN.INP");
ofstream fo("HCN.OUT");

struct hcn{
       ll x1, x2, y1, y2;
       ll d;
};

hcn a[100];
int n;

void nhap(){
     fi >> n;
     for(int i = 0; i < n; i++){
             fi >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
             a[i].d = 0;
     }
}

void solve(){
     int i, j;
     for(i = 0; i < n; i++){
           for(j = 0; j < n; j++){
                 if(i != j){
                      if(a[j].x1 <= a[i].x1 && a[j].y1 <= a[i].y1 && a[j].x2 >= a[i].x2 && a[j].y2 >= a[j].y2){
//                          for(int z = 0; z < n; z++) cout << a[z].d << " ";
//                          cout << endl;
                          a[i].d ++;
                      }
                 }
           }
     }
     int max = 0;
     for(int i = 0; i < n; i++) if(a[i].d >= max) max = a[i].d;
     fo << max;
}

int main(){
    nhap();
    solve();
    fi.close();
    fo.close();
    return 0;
}
