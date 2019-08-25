#include <stdio.h>
#include <math.h>

double res = 0;
int n;

void nhap(){
    scanf("%d",&n);
}

void solve(){
    for(int i = 1; i <= n; i++) res = res + (double)(1/pow(i,3));
    printf("%0.3lf",res);
}

int main(){
    nhap();
    solve();
    return 0;
}
