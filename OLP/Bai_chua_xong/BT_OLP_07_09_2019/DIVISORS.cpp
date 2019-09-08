#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fi("DIVISORS.INP");
ofstream fo("DIVISORS.OUT");
typedef unsigned long long int ll;
const int mmax = 1e6;

int n;
bool t[mmax];
vector<int> a;
ll res, nn;

void nhap(){
    fi >> n;
    ll i, j;
    for(i = 0; i < mmax; i++) t[i] = true;
    for(i = 2; i < mmax; i++) if(t[i]){
        a.push_back(i);
        for(j = i * i; j < mmax; j = j + i) t[j] = false;
    }
}

void solve(){
    nn = 1;
    ll i, j;
    for(i = 2; i <= n; i++) nn = nn * i;
    res = 1;
    int dem;
    for(i = 0; i < a.size(); i++){
        if(nn <= 0) break;
        dem = 0;
        while(nn % a[i] == 0){
            dem++;
            nn /= a[i];
        }
        if(dem != 0) res = res * (1 + dem);
    }
    fo << res-1;
}

int main(){
    nhap();
    solve();
    fi.close();
    fo.close();
    a.clear();
    return 0;
}
