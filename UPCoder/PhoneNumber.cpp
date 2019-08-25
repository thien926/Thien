#include<iostream>
using namespace std;
void quaylui(string a,int i){
	int x=a[i]-'0';
	switch(x){
		case 2:for(int j=0;j<3;j++){
		       switch(j){
		       	case 0:a[i]='a';break;
		       	case 1:a[i]='b';break;
		       	case 2:a[i]='c';break;
			   }
			   if(i==a.length()-1) cout<<a<<" ";
			   else quaylui(a,i+1);
		}
		break;
		case 3:for(int j=0;j<3;j++){
		       switch(j){
		       	case 0:a[i]='d';break;
		       	case 1:a[i]='e';break;
		       	case 2:a[i]='f';break;
			   }
			   if(i==a.length()-1) cout<<a<<" ";
			   else quaylui(a,i+1);
		}
		break;
		case 4:for(int j=0;j<3;j++){
		       switch(j){
		       	case 0:a[i]='g';break;
		       	case 1:a[i]='h';break;
		       	case 2:a[i]='i';break;
			   }
			   if(i==a.length()-1) cout<<a<<" ";
			   else quaylui(a,i+1);
		}
		break;
		case 5:for(int j=0;j<3;j++){
		       switch(j){
		       	case 0:a[i]='j';break;
		       	case 1:a[i]='k';break;
		       	case 2:a[i]='l';break;
			   }
			   if(i==a.length()-1) cout<<a<<" ";
			   else quaylui(a,i+1);
		}
		break;
		case 6:for(int j=0;j<3;j++){
		       switch(j){
		       	case 0:a[i]='m';break;
		       	case 1:a[i]='n';break;
		       	case 2:a[i]='o';break;
			   }
			   if(i==a.length()-1) cout<<a<<" ";
			   else quaylui(a,i+1);
		}
		break;
		case 7:for(int j=0;j<4;j++){
		       switch(j){
		       	case 0:a[i]='p';break;
		       	case 1:a[i]='q';break;
		       	case 2:a[i]='r';break;
		       	case 3:a[i]='s';break;
			   }
			   if(i==a.length()-1) cout<<a<<" ";
			   else quaylui(a,i+1);
		}
		break;
		case 8:for(int j=0;j<3;j++){
		       switch(j){
		       	case 0:a[i]='t';break;
		       	case 1:a[i]='u';break;
		       	case 2:a[i]='v';break;
			   }
			   if(i==a.length()-1) cout<<a<<" ";
			   else quaylui(a,i+1);
		}
		break;
		case 9:for(int j=0;j<4;j++){
		       switch(j){
		       	case 0:a[i]='w';break;
		       	case 1:a[i]='x';break;
		       	case 2:a[i]='y';break;
		       	case 3:a[i]='z';break;
			   }
			   if(i==a.length()-1) cout<<a<<" ";
			   else quaylui(a,i+1);
		}
		break;
	}
}
int main(){
	string a;
//	cout<<"nhap chuoi tu 2-9:";
	cin>>a;
//	cout<<endl;
	quaylui(a,0);
//	cout<<endl;
	return 0;
}
