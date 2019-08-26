#include <iostream>
#include <cstdio>

using namespace std;
char *s, q;
int n;

void set(){
    cin >> q >> n;
    s = new char[n];
    for(int i = 0; i < n; i++){
        fflush(stdin);
        cin >> s[i];
    }
}

bool compare(int a, int b, int k){
    switch(k){
        case 1: return a < b;
        case -1: return a > b;
        default : return false;
    }
}

void exch(char &a, char &b){
    char r = a;
    a = b;
    b = r;
}

void quicksort(int l, int r, int k){
    char x = s[(l+r)/2];
    int i = l, j = r;
    do{
        while(compare(s[i], x, k)) i++;
        while(compare(x, s[j], k)) j--;
        if(i <= j) exch(s[i++], s[j--]);
    }
    while(i < j);
    if(l < j) quicksort(l, j, k);
    if(i < r) quicksort(i, r, k);
}

void solve(){
    if(q == 'A'){
        quicksort(0, n-1, 1);
    }
    else{
        quicksort(0, n-1, -1);
    }
    for(int i = 0; i < n; i++) cout << s[i] << " ";
    delete []s;
}

int main(){
    set();
    solve();
    return 0;
}
