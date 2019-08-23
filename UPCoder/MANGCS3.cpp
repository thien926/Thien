#include<iostream>
using namespace std;
int main()
{
    int k,t, i = 0; 
    cin>>k;
    while(cin>>t) {   
         if(k != i )  
             cout<<t<<" ";    
             i++; 
    }
    return 0;   
}