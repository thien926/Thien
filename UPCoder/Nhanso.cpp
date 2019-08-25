#include<iostream>
#include<string>
#include<sstream>
using namespace std;

void exch(char &a,char &b){
	char r=a;a=b;b=r;
}

string add(string a,string b){
	int k,i,j;
	int nho=0;
	if(a.length()>b.length()){
		k=a.length()-b.length();
		for(i=0;i<k;i++) b="0"+b;
	}
	else{
		k=b.length()-a.length();
		for(i=0;i<k;i++) a="0"+a;
	}
	a="0"+a;b="0"+b;                   
	string res="0";
	for(i=a.length()-1;i>=0;i--){
		k=(a[i]-'0')+(b[i]-'0')+nho;
		if(k>=10){
			nho=1;
			k=k%10;
			ostringstream convert;
			convert<<k;
			res=res+convert.str();
		}
		else{
			nho=0;
			ostringstream convert;
			convert<<k;
			res=res+convert.str();
		}
	}
	if(res[res.length()-1]=='0') res.erase(res.length()-1,1);
	res.erase(0,1);
	i=0;j=res.length()-1;
	while(i<j){
		exch(res[i++],res[j--]);
	}
	return res;
}
string mul(string a,string b){
	string res="0",r;
	int k,i,j,nho,d=0;
	bool dau=true;
	if(a[0]=='-'||b[0]=='-'){
	    if(a[0]=='-'&&b[0]!='-'){
	        dau=false;
	        a=a.substr(1,a.length()-1);
	    }
	    if(a[0]!='-'&&b[0]=='-'){
	        dau=false;
	        b=b.substr(1,b.length()-1);
	    }
	    if(a[0]=='-'&&b[0]=='-'){
	        a=a.substr(1,a.length()-1);b=b.substr(1,b.length()-1);
	    }
	} 
	for(i=b.length()-1;i>=0;i--){
		r="0";nho=0;
		for(j=a.length()-1;j>=0;j--){
			k=(b[i]-'0')*(a[j]-'0')+nho;
			if(k<10){
				nho=0;
				ostringstream convert;
				convert<<k;
				r=convert.str()+r;
			}
			else{
				nho=k/10;k=k%10;
				ostringstream convert;
				convert<<k;
				r=convert.str()+r;
			}
		}
		if(nho!=0){
			ostringstream convert;
			convert<<nho;
			r=convert.str()+r;
		}
		r.erase(r.length()-1,1);
		for(k=0;k<d;k++) r=r+"0";
		d++;
		res=add(res,r);
	}
	for(i=0;i<res.length();i++) if(res[i]!='0') break;
	if(i>=res.length()) return "0";
	if(!dau) res="-"+res;
	return res;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<mul(a,b)<<endl;
	return 0;
}
