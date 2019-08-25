// khong phai cua minh
#include<bits/stdc++.h>

using namespace std;
#define maxn 85
#define maxl 12
#define ll long long

ll t, a, b, k, dp[maxl][maxn][maxn][4];

void init(){
    for (int i = 0; i < maxl; i++)
        for (int r1 = 0; r1 < maxn; r1++)
            for (int r2 = 0; r2 < maxn; r2++)
                for (int sta = 0; sta < 3; sta++) dp[i][r1][r2][sta] = 0;
}

string change(ll n){
    if (n == 0) return "0";
    else{
        string s ="";
        while (n > 0){
            s = (char)(n%10 + '0') + s;
            n /= 10;
        }
        return s;
    }
}

int cal(int n){
    init();
    string s = change(n);
    int m = s.size();
    for (int x = 1; x <= 9; x++){
        if (x < s[0] - '0') dp[1][x % k][x % k][0]++;
        else if (x == s[0] - '0') dp[1][x % k][x % k][1]++;
        else dp[1][x % k][x % k][2]++;
    }

    for (int i = 1; i < m; i++)
        for (int r1 = 0; r1 < k; r1++)
            for (int r2 = 0; r2 < k; r2++)
                for (int sta = 0; sta < 3; sta++){
                    if (dp[i][r1][r2][sta] == 0) continue;
                    ll cur = dp[i][r1][r2][sta];
                    for (int x = 0; x <= 9; x++){
                        if (sta == 0 || sta == 2)
                            dp[i+1][(r1*10+x)%k][(r2+x)%k][sta] += cur;
                        else{
                            if (x < s[i] - '0'){
                                dp[i+1][(r1*10+x)%k][(r2+x)%k][0] += cur;
                            }
                            else if (x == s[i] - '0'){
                                dp[i+1][(r1*10+x)%k][(r2+x)%k][1] += cur;
                            }
                            else dp[i+1][(r1*10+x)%k][(r2+x)%k][2] += cur;
                        }
                    }
    }
    
    ll res = 0;
    for (int i = 1; i < m; i++)
        for (int sta = 0; sta < 3; sta++){
            res += dp[i][0][0][sta];
        }
    for (int sta = 0; sta < 2; sta++) res += dp[m][0][0][sta];
    
    return res;
    
}

int main(){
    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> a >> b >> k;
        cout << "Case " << i <<": ";
        if (k > 82) cout << 0 << endl;
        else cout << cal(b) - cal(a-1) << endl;
    }
    return 0;
}
