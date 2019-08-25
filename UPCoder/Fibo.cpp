#include<iostream>
using namespace std;
typedef unsigned long long int ll;

struct fibo{
    ll x1 = 1;
    ll y1 = 1;
    ll x2 = 1;
    ll y2 = 0;
};

ll n, mod;
fibo A;

ll add(ll a, ll b){
    return ((a % mod) + (b % mod)) % mod;
}

ll mul(ll a, ll b){
    a = a % mod;
    ll res = 0;
    while(b){
        if(b % 2 != 0) res = add(res, a);
        a = add(a, a);
        b = b / 2;
    }
    return res;
}

fibo matran(fibo a, fibo b){
    fibo c;
    c.x1 = (mul(a.x1, b.x1) + mul(a.y1, b.x2)) % mod;
    c.x2 = (mul(a.x2, b.x1) + mul(a.y2, b.x2)) % mod;
    c.y1 = (mul(a.x1, b.y1) + mul(a.y1, b.y2)) % mod;
    c.y2 = (mul(a.x2, b.y1) + mul(a.y2, b.y2)) % mod;
    return c;
}

fibo xuli(ll y){
    fibo r;
    r.x1 = 1;
    r.y1 = 0;
    r.x2 = 0;
    r.y2 = 1;
    while(y){
        if(y % 2) r = matran(r, A);
        A = matran(A, A);
        y = y / 2;
    }
    return r;
}

int main(){
    cin >> n >> mod;
    A = xuli(n);
    cout << A.x2 << endl;
    return 0;
}
