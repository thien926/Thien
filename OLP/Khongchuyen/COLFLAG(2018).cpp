#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
const int mmax = 256;
ifstream fi("INPUT.INP");
ofstream fo("OUTPUT.OUT");

int n, m;
int dd[mmax];

void set(){
    fi >> n >> m;
    int x, i;
    for(i = 0; i < n; i++){
        fi >> x;
        dd[x]++;
    }
    for(i = 0; i < m; i++){
        fi >> x;
        dd[x]++;
    }
}

void solve(){
    int i;
    sort(dd+0, dd+mmax, greater<int>());
    int d = 0;
    for(i = 0; i < mmax; i++){
        d = d + dd[i];
        if(d > n) break;
    }
    if(d - dd[i] == n) fo << i;
    else fo << i + 1;
}

int main(){
    set();
    solve();
    fi.close();
    fo.close();
    return 0;
}
