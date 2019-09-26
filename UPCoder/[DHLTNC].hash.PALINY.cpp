#include <iostream>

using namespace std;

string s;
int res = 1;

void nhap(){
    cin >> s;
}

void solve(){
    int i, j;
    for(i = 1; i < s.length()-1; i++){
        j = 0;
        while(i - j >= 0 && i + j < s.length() && s[i-j] == s[i+j]) j++;
        if(i - j < 0 || i + j >= s.length() || s[i-j] != s[i+j]) j--;
        if(res < 2*j+1) res = 2*j+1; 
    }

    for(i = 0; i < s.length()-1; i++) if(s[i] == s[i+1]){
        j = 0;
        while(i-j >= 0 && i+1+j < s.length() && s[i-j] == s[i+1+j]) j++;
        if(i - j < 0 || i + 1 + j >= s.length() || s[i-j] != s[i+1+j]) j--;
        if(res < 2*j+2) res = 2*j+2;
    }
    cout << res;
}

int main(){
    nhap();
    solve();
}
