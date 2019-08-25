#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <ctime>

using namespace std;
typedef unsigned long long int ll;
const int w = 1e9;
vector<int> a;
bool *b;

int n, mmax, snt1, snt2;

void nhap(){
    mmax = sqrt(w);
    b = new bool[mmax+1];
    int i, j;
    for(i = 0; i <= mmax; i++) b[i] = true;
    for(i = 2; i <= mmax; i++) if(b[i]){
        for(j = i*i; j <= mmax; j = j + i) b[j] = false;
    }
    b[0] = b [1] = false;
}

void solve(){
    int i, j, res;
    ll kk;
    cin >> n;
    if(n < 6){
        for(j = 0; j < n; j++) if(j*j%n == j) cout << j << " ";
    }
    else{
        kk = sqrt(n);
        for(j = 2; j <= kk; j++) if(b[j] && n % j == 0) break;
        snt1 = j;
        snt2 = n/j;
        a.push_back(0);
        a.push_back(1);
        for(j = 1 ;res = snt1*j, res < n; j++){
            kk = (ll)res*res;
            if(kk % n == res) a.push_back(res);
        }
        
        for(j = 1 ;res = snt2*j, res < n; j++){
            kk = (ll)res*res;
            if(kk % n == res) a.push_back(res);
        }
        
        sort(a.begin(), a.end());
        for(j = 0; j < a.size(); j++) cout << a[j] << " ";
         a.clear();
    }
}

int main(){
    nhap();
    solve();
    delete []b;
    return 0;
}
