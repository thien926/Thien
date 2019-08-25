#include <iostream>

using namespace std;

int main(){
    int A, B, M, a_b, m, res;
    cin >> A >> B >> M;
    if(M == A){
        cout << 1;
        return 0;
    }
    a_b = A - B;
    res = (M - B)/a_b - 1;
    m = a_b * res;
    while(m < M){
        res++;
        m = m + A;
        if(m >= M){
            break;
        }
        m = m - B;
    }
    cout << res;
    return 0;
}
