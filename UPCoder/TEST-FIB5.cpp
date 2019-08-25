#include <iostream>

using namespace std;
typedef unsigned long long int ll;

ll n;
ll *a;

void nhap(){
    cin >> n;
    a = new ll[n+1];
}

ll fibo(ll nn){
    if(nn < 3){
        a[nn] = 1;
    }
    else{
        if(nn % 2 == 0){
            a[nn] = (2 * fibo(nn/2-1) + fibo(nn / 2)) * fibo(nn/2);
        }
        else{
            a[nn] = fibo(nn/2 + 1)*fibo(nn/2 + 1) + fibo(nn/2)*fibo(nn/2);
        }
    }
    return a[nn];
}

int main(){
    nhap();
    cout << fibo(n);
    delete []a;
    return 0;
}
