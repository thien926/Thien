#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node* ref;

struct node{
    int key;
    ref next;
};

ref get(int k){
    ref p;
    p=new node;
    if(p==NULL) exit(0);
    p->key=k;
    p->next=NULL;
    return p;
}

void addlast(ref &head, ref &tail, int k){
    ref p=get(k);
    if(head==NULL){
        head=tail=p;
    }
    else{
        tail->next=p;
        tail=p;
    }
}

void nhap(ref &head, ref &tail, int n){
    int k;
    for(int i = 0; i < n; i++){
        cin>>k;
        addlast(head,tail,k);
    }
}

void xuly(ref &head, ref &tail, int t){
    if(head==NULL) return;
    ref p;
    for(int i=0;i<t;i++){
        p=head;
        head=head->next;
        tail->next=p;
        tail=p;
        tail->next=NULL;
    }
}

void duyet(ref head){
    ref p;
    if(head==NULL) return;
    for(p = head; p ; p = p->next) cout<<p->key<<" ";
}

void destroy(ref &head){
    ref p;
    while(head){
        p=head;
        head=head->next;
        delete p;
    }
}

int main(){
    ref head=NULL,tail=NULL;
    int n,t;
    cin>>n>>t;
    nhap(head,tail,n);
//    duyet(head);cout<<endl;
    xuly(head,tail,t);
    duyet(head);
    destroy(head);
    return 0;
}
