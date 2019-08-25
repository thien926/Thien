#include <iostream>

using namespace std;

int n, k;
char a, b, c;

void nhap(){
    cin >> n;
    k = n;
    a = 'A';
    b = 'B';
    c = 'C';
}

void solve(char aa, char bb, char cc, int nn, int kk){
    if(nn <= 1){
        cout << kk << " " << aa << " " << cc << endl;
        return;
    }
    solve(aa, cc, bb, nn - 1, kk - 1);
    solve(aa, bb, cc, 1, kk);
    solve(bb, aa, cc, nn-1, kk-1);
}

int main(){
    nhap();
    solve(a, b, c, n, k);
    return 0;
}
