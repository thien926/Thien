#include<iostream>
#include<sstream>
#include<cstdlib>
using namespace std;
typedef struct node* ref;

struct node{
	int key;
	ref next;
};

ref get(int k){
	ref p=(ref)malloc(sizeof(struct node));
	if(p==NULL) exit(0);
	p->key=k;
	p->next=NULL;
	return p;
}

void addlast(ref &head, ref &tail, int k){
	ref p = get(k);
	if(head==NULL){
		head=tail=p;
	}
	else{
		tail->next=p;
		tail=p;
	}
}

void nhap(ref &head, ref &tail, int &n){
	cin>>n;
	int k;
	for(int i=0;i<n;i++){
		cin>>k;
		addlast(head,tail,k);
	}
}

void left(ref &head, ref &tail, int n){
	if(head== NULL) return;
	ref p;
	for(int i=0;i<n;i++){
		p=head;
		head=head->next;
		tail->next=p;
		tail=p;
		tail->next=NULL;
	}
}

void right(ref &head, ref &tail, int n){
	if(head==NULL) return ;
	ref r,p;
	for(int i=0;i<n;i++){
		for(p=head;p;p=p->next){
			r=p->next;
			if(r->next==NULL) break;
		}
		p->next=NULL;
		r->next=head;
		head=r;
		tail=p;
	}
}

void duyet(ref head){
	if(head==NULL) return;
	ref p;
	for(p=head;p;p=p->next) cout<<p->key<<" ";
	cout<<endl;
}

void xuly(ref &head, ref &tail, int &t,string &a){
	cin>>t;
	int x=0;
	for(int i=0;i<t;i++){
		cin>>a;
		if(a[0]=='<'){
			a.erase(0,1);a.erase(0,1);
			stringstream convert(a);
			convert>>x;
			left(head,tail,x);
		}
		else{
			a.erase(0,1);a.erase(0,1);
			stringstream convert(a);
			convert>>x;
			right(head,tail,x);
		}
		duyet(head);
	}
}

void destroy(ref &head){
	if(head==NULL) return;
	ref p;
	while(head){
		p=head;
		head=head->next;
		free(p);
	}
}

int main(){
	int n,t;
	string a;
	ref head=NULL,tail=NULL;
	nhap(head,tail,n);
	xuly(head,tail,t,a);
	destroy(head);
	return 0;
}
