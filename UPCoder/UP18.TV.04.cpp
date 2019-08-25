//nguyen tan thong
#include<bits/stdc++.h>
using namespace std;

int vis[1000][100000];
int _res;
//res
int res(int n){
    int tmp=0;
    do tmp+=n%10;
    while(n/=10);
    return tmp;
}
//bfs
void bfs (int n){
    int go;
    int per; 
    queue  < pair <int,int> > _q;
    pair <int,int> _p;
    _q.push(make_pair(0,0));
    vis[0][0]=1;
    
    while(!_q.empty()){
        
        _p = _q.front();
        _q.pop();
        
        for(int i=(_p.first)?0:1;i<10;i++){
            go = _p.first + i;
            per = (_p.second *10 +i) %n;
            
            if(go >= _res) break;
            
            if(vis[go][per] == 0) {
                vis[go][per] =1;
                _q.push(make_pair(go,per));
            }
            if(per == 0 && go < _res) _res = go;
        }
        
        
    }
}
//main
int main(){
    int n;
    cin>>n;
    _res = res(n);
    bfs(n);
    cout<<_res;
}
