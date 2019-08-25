#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int k, q;
    for(int i = 7; i < 10; i++){
        k = (i -6)*pow(10,2) + (i - 3)*pow(10,1) + i;
        q = (i -6)*pow(10,3) + (i - 3)*pow(10,2) + i;
        if(q - k == 2250){
            cout << k;
            return 0;
        }
    }
}
