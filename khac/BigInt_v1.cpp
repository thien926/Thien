#include <iostream>
#include <string>

using namespace std;

string Add(string a, string b);
string Subtract(string a, string b);

int ToNum(char c){
    return c - '0';
}

char ToChar(int c){
    return char(c) + 48;
}

void Sync(string &a, string &b){
    while(a.length() > b.length()) b = "0" + b;
    while(a.length() < b.length()) a = "0" + a;
}

bool sign(string s){
    if(s[0] == '-') return false;
    return true;
}

int Compare(string a, string b){
    if(a.length() != b.length()) Sync(a, b);
    for(int i = 0; i < a.length(); i++){
        if(a[i] < b[i]) return -1;
        if(a[i] > b[i]) return 1;
    }
    return 0;
}

//Cộng 2 số nguyên
string Add(string a, string b){
    // a âm và b âm
    if(!sign(a) && !sign(b)){
        a.erase(0, 1); b.erase(0, 1);
        return "-" + Add(a, b);
    }

    //a âm b dương
    if(!sign(a) && sign(b)){
        a.erase(0, 1);
        return Subtract(b, a);
    }

    //a dương b âm
    if(sign(a) && !sign(b)){
        b.erase(0, 1);
        return Subtract(a, b);
    }

    //a dương b dương
    Sync(a, b);
    string res = "";
    int nho = 0, sum = 0, i;
    for(i = a.length()-1; i >= 0; i--){
        sum = ToNum(a[i]) + ToNum(b[i]) + nho;
        res = ToChar(sum%10) + res;
        if(sum >= 10) nho = sum/10;
        else nho = 0;
    }
    if(nho > 0) res = ToChar(nho) + res;
    for(i = 0; i < res.length(); i++) if(res[i] != '0') break;
    res.erase(0, i);
    return res;
}

string Subtract(string a, string b){
    // a == b thì xuất 0
    if(a == b) return "0";
    //a dương b âm
    if(sign(a) && !sign(b)){
        b.erase(0, 1);
        return Add(a, b);
    }

    //a âm b âm
    if(!sign(a) && !sign(b)){
        a.erase(0, 1); b.erase(0, 1);
        return Subtract(b, a);
    }

    //a âm b dương
    if(!sign(a) && sign(b)){
        a.erase(0, 1);
        return "-" + Add(a, b);
    }

    //a dương b dương
    int i;
    Sync(a, b);
    string res = "";
    int sum = 0, nho = 0;
    if(Compare(a, b) < 0) return "-" + Subtract(b, a);
    for(i = a.length()-1; i >= 0; i--){
        sum = ToNum(a[i]) - ToNum(b[i]) - nho;
        if(sum < 0){
            sum = sum + 10;
            nho = 1;
        }
        else nho = 0;
        res = ToChar(sum) + res;
    }
    for(i = 0; i < res.length(); i++) if(res[i] != '0') break;
    res.erase(0, i);
    return res;
}

//nhân 1 số lớn với số có 1 chữ số
string Mull(string a, char c){
    string res = "";
    int i, sum = 0, nho = 0, c1;
    c1 = ToNum(c);
    for(i = a.length()-1; i >= 0; i--){
        sum = ToNum(a[i])*c1 + nho;
        res = ToChar(sum%10) + res;
        if(sum < 10) nho = 0;
        else nho = sum/10;
    }
    if(nho > 0) res = ToChar(nho) + res;
    return res;
}
//nhân 2 số lớn
string Mul(string a, string b){
    // a và b khác dấu
    if(sign(a) != sign(b)){
        if(!sign(a)) a.erase(0, 1);
        else b.erase(0, 1);
        return "-" + Mul(a, b);
    }
    // a và b cùng dâu
    if(!sign(a)){
        a.erase(0, 1); b.erase(0, 1);
    }

    string res = "0", r = "";
    int i, j;
    for(i = a.length()-1; i >= 0; i--){
        r = Mull(b, a[i]);
        for(j = a.length()-1; j > i; j--) r = r + "0";
        res = Add(res, r);
    }
    for(i = 0; i < res.length(); i++) if(res[i] != '0') break;
    res.erase(0, i);
    return res;
}
//chia lấy phần nguyên 2 số lớn
string Div(string a, string b){
    string res = "";
    // a và b khác dấu
    if(sign(a) != sign(b)){
        if(!sign(a)){
            res = a.substr(1, a.length()-1);
            res = Subtract(res, b);
            if(res[0] == '-') return "0";//|a| < |b|
            a.erase(0, 1);
            return "-" + Div(a, b);
        }
        else{
            b.erase(0, 1);
            res = a;
            res = Subtract(res, b);
            if(res[0] == '-') return "0"; // |a| < |b|
            return "-" + Div(a, b);
        }
    }
    // a và b cùng dấu
    //a và b âm
    if(!sign(a)){
        a.erase(0, 1); b.erase(0, 1);
    }
    res = Subtract(a, b);
    if(res[0] == '-') return "0";
    //a và b dương
    string r = "", res1 = "";
    int i, d, b1;
    b1 = ToNum(b[0]);
    res = "";
    r = a.substr(0, b.length()-1);
    for(i = b.length()-1; i < a.length(); i++){
        r = r + a[i];
        if(r[0] == '0'){
            res = res + "0";
            r = "";
            continue;
        }
        if(r.length() == b.length()){
            d = ToNum(r[0])/b1;
            if(d != 0){
                res1 = Subtract(r, Mull(b, ToChar(d)));
                while(res1[0] == '-'){
                    d--;
                    res1 = Subtract(r, Mull(b, ToChar(d)));
                }
                res = res + ToChar(d);
                if(res1 == "0") r = "";
                else r = res1;
            }
        }
        else if(r.length() > b.length()){
            d = (ToNum(r[0])*10 + ToNum(r[1]))/b1;
            if(d != 0){
                res1 = Subtract(r, Mull(b, ToChar(d)));
                while(res1[0] == '-'){
                    d--;
                    res1 = Subtract(r, Mull(b, ToChar(d)));
                }
                res = res + ToChar(d);
                if(res1 == "0") r = "";
                else r = res1;
            }
        }
    }
    return res;
}
//chia dư 2 số lớn
string Mod(string a, string b){
    return Subtract(a, Mul(Div(a, b), b));
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << Div(a, b);
    return 0;
}
