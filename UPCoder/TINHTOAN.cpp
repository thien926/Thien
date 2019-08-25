#include <stdio.h>
typedef long long int ll;

ll a, b;

void nhap(){
    scanf("%lld%lld", &a, &b);
}

void solve(){
    printf("%lld+%lld=%lld\n", a, b, a+b);
    printf("%lld-%lld=%lld\n", a, b, a-b);
    printf("%lld*%lld=%lld\n", a, b, a*b);
    printf("%lld/%lld=%0.1lf", a, b, 1.0*a/b);
}

int main(){
    nhap();
    solve();
    return 0;
}
