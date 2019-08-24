#include <iostream>
//#include <fstream>

using namespace std;
typedef unsigned long long int ll;
const int smg = 4;
//ofstream fo("OUTPUT.OUT");

struct cn{
    int r;
    int d;
};

int n;
ll tongmul, dt;
cn a[smg+1];
bool t[smg+1];
bool tt;
string *s;

void set(){
    tt = false;
    tongmul = 0;
    for(int i = 1; i <= smg; i++){
        cin >> a[i].r >> a[i].d;
        tongmul = tongmul + (ll)a[i].r*(ll)a[i].d;
        t[i] = true;
    }
}

void kt(){
    for(int i = 1; i <= smg; i++) if(t[i]){
        dt = (ll)a[i].d*(ll)a[i].r;
//        fo <<"i : " << i << " kt: " << a[i].r << " " << a[i].d << endl;
    }
    if(dt == tongmul) tt = true;
}

void init(int kk){
    if(kk >= smg){
        kt();
        return;
    }
    int i, j;
    for(i = 1; i <= smg; i++) if(t[i]){
        t[i] = false;
        for(j = 1; j <= smg; j++) if(t[j]){
            if(a[i].r == a[j].r){
                a[j].d = a[j].d + a[i].d;
                init(kk+1);
                if(tt) return;
                a[j].d = a[j].d - a[i].d;
            }
            if(a[i].r == a[j].d){
                a[j].r = a[j].r + a[i].d;
                init(kk+1);
                if(tt) return;
                a[j].r = a[j].r - a[i].d;
            }
            if(a[i].d == a[j].r){
                a[j].d = a[j].d + a[i].r;
                init(kk+1);
                if(tt) return;
                a[j].d = a[j].d - a[i].r;
            }
            if(a[i].d == a[j].d){
                a[j].r = a[j].r + a[i].r;
                init(kk+1);
                if(tt) return;
                a[j].r = a[j].r - a[i].r;
            }
        }
        t[i] = true;
    }
}

void solve(){
    cin >> n;
    s = new string[n];
    for(int i = 0; i < n; i++){
//        fo << " mang " << i + 1 << " : " << endl;
        set();
        init(1);
        if(tt) s[i] = s[i] + "YES";
        else s[i] = s[i] + "NO";
    }
    for(int i = 0; i < n; i++) cout << s[i] << endl;
}

int main(){
    solve();
    delete []s;
//    fo.close();
    return 0;
}