#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>
#include<vector>
#define MAX_ALPHA 4
using namespace std;

int dp[1005][1005];	//dp[�Ҽ{1~i������][�{�b�Ҧb���A(�r�����A)]=min���ܦ��� 
int h[300];

struct Trie{
	int next[1005][MAX_ALPHA];	//next[���A(���N��)][�p�G�Y��'��'alpha]=�ಾ�쪺�U�@�Ӫ��A 
	int fail[1005];		//fail[���A]=fail�쪺���A 
	bool end[1005]; 	//�O�_�O�פ�A(���D���岫��]) 
	int root;			//root�����A�N��
	int L;				//���A�Ӽ�(���]�Aroot) 
	 
	void init(){
		root=0;
		L=0;
		memset(next,-1,sizeof(next));
		memset(fail,0,sizeof(fail));
		memset(end,0,sizeof(end));
	}
	
	void insert(string s){
		int now=root;
		for(int i=0;i<s.length();i++){
			if(next[now][h[s[i]]]==-1)
				next[now][h[s[i]]]=++L;
			now=next[now][h[s[i]]];
		}
		end[now]=1;
	}
	
	void build_aca(){
		//fail[root]=root
		queue<int> que;
		
		for(int i=0;i<MAX_ALPHA;i++){
			if(next[0][i]==-1)
				next[0][i]=0;
			else{
				//fail[next[0][i]]=0;
				que.push(next[0][i]);
			}
		}

		while(!que.empty()){
			int now=que.front();
			que.pop();
			for(int i=0;i<MAX_ALPHA;i++){
				int _fail=next[fail[now]][i];
				if(next[now][i]==-1)
					next[now][i]=_fail;
				/*
				a) �p�Gnow->next[i]��NULL�A����Nnow->next[i]���Vnow�����ѫ��w��i���l���I, 
				�Ynow->next[i] = now->fail->next [i];
				*/
				
				else{
					fail[next[now][i]]=_fail;
					end[next[now][i]]|=end[_fail];
					que.push(next[now][i]);
				}
				/*
				b) �p�Gnow->next[i]������NULL�A�h�ݭn�c�ynow->next[i]�����ѫ��w�A�ѩ�a)���ާ@�A
				�ڭ̪��Dnow�����ѫ��w�@�w�s�b�@��i���l���I�A�Ynow->fail->next[i]�A
				����ڭ̱Nnow->next[i]�����ѫ��w���V���A�Ynow->next[i]->fail = now->fail->next[i]�F
				*/ 
			}	
		}		
	}
	
};

int main(){
	h['A']=0; h['G']=1; h['C']=2; h['T']=3; 
	
	int N,CASE=0;
	while(cin>>N){
		if(N==0)
			return 0;
			
		Trie trie;
		trie.init();
		string s;	
		for(int i=0;i<N;i++){
			cin>>s;
			trie.insert(s);
		}
		trie.build_aca();
		memset(dp,0x6f,sizeof(dp));
		dp[0][0]=0;		//[�r����׬��s][���A��'��L'] 
		
		cin>>s;
		for(int i=0;i<s.length();i++){
			for(int j=0;j<=trie.L;j++){
				if(dp[i][j]==0x6f6f)
					continue;
				for(int a=0;a<MAX_ALPHA;a++){
					int to_state=trie.next[j][a];
					if(!trie.end[to_state])
						dp[i+1][to_state]=min(dp[i+1][to_state],dp[i][j]+((h[s[i]]==a)?0:1));
				}
			}
		}
		
		int ans=0x6f6f;
		for(int i=0;i<=trie.L;i++){
			ans=min(ans,dp[s.length()][i]); 
		}
		if(ans==0x6f6f)
			ans=-1; 
		cout<<"Case "<<++CASE<<": "<<ans<<endl;
	}
	
	return 0;
} 
