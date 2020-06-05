#include<bits/stdc++.h>
#define MAX_ALPHA 26
using namespace std;
int N;
int cnt[155];
//char pattern[155][100];
//char S[1000005];
string pattern[155];
string S;

struct Node{
	int who;	//編號1~n 
	//int cnt;	//找到幾個此pattern 
	Node *fail;
	Node *child[MAX_ALPHA];
	Node(){
		who=0;
		//cnt=0;
		fail=NULL;
		memset(child,'\0',sizeof(child));
	}
};

void build_trie(const string str,Node *root,int who){
	Node *p=root;
	int i=0,idx;
	while(str[i]){
		idx=str[i]-'a';
		if(p->child[idx]==NULL){
			p->child[idx]=new Node();
		}
		p=p->child[idx];
		i++;
	}
	p->who=who;
	//p->cnt++;
}

void build_ac_automaton(Node *root){
	Node *now,*p;
	root->fail=NULL;
	queue<Node *> que;
	que.push(root);
	while(!que.empty()){
		now=que.front();
		que.pop();
		for(int i=0;i<MAX_ALPHA;i++){
			if(now->child[i]==NULL)
				continue;
			que.push(now->child[i]);
			p=now->fail;
			while(p!=NULL&&p->child[i]==NULL)
				p=p->fail;
			if(p==NULL)
				now->child[i]->fail=root;
			else
				now->child[i]->fail=p->child[i];	
		}
	}
}

void free_ac_automaton(Node *root){
	Node *now;
	queue<Node *> que;
	que.push(root);
	while(!que.empty()){
		now=que.front();
		que.pop();
		for(int i=0;i<MAX_ALPHA;i++){
			if(now->child[i]==NULL)
				continue;
			que.push(now->child[i]);
		}
		free(now);
	} 
}

void query(string str,Node *root){
	Node *now,*p;
	int idx,i=0;
	now=root;
	while(str[i]){
		idx=str[i]-'a';
		//cout<<idx<<" "; 
		while(now!=root&&now->child[idx]==NULL){
			now=now->fail;
		}
		now=now->child[idx];
		if(now==NULL)
			now=root; 
		p=now;
		while(p!=root){
			if(p->who)
				cnt[p->who]++;
			p=p->fail;
		}
		
		i++;
		//cout<<"OK"<<endl;	
	}
	//cout<<"query OK"<<endl;
}

int main(){
	
	while(cin>>N){
		if(N==0)
			return 0;
		memset(cnt,0,sizeof(cnt));
		
		Node *root=new Node();
		for(int i=1;i<=N;i++){
			cin>>pattern[i];
			build_trie(pattern[i],root,i);
		}
		build_ac_automaton(root);
		
		cin>>S;
		query(S,root);
		int ans=0;
		for(int i=1;i<=N;i++){
			ans=max(ans,cnt[i]);
		}
		cout<<ans<<endl;
		for(int i=1;i<=N;i++){
			if(cnt[i]==ans)
				cout<<pattern[i]<<endl;
		}
		free_ac_automaton(root);
	}

	return 0;
} 
