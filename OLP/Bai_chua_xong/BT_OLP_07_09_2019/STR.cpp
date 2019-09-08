#include <iostream>
#include <fstream>

using namespace std;
ifstream fi("SUBSTR.INP");
ofstream fo("SUBSTR.OUT");

string s;

int dau = 0, len = 0, dau1 = 0;
int d[256] = {0};

void solve(){
    fi >> s;
    int i, j;
    for(i = 0; i < s.length(); i++){
        if(d[s[i]] == 0){
            d[s[i]] = i+1;
            
        }
        else{
            if(i+1 - d[s[i]] > len){
                len = i+1 - d[s[i]];
                dau = d[s[i]];
                d[s[i]] = i+1;
                j = i+1;
            }
        }
    }
    if(i+1 - j > len){
        fo << j << " " << i+1 - j;
        return;
    }
    fo << dau << " " << len;
}

int main(){
    solve();
    fi.close();
    fo.close();
    return 0;
}
