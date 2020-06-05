#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>
#include<vector>
#define MAX_ALPHA 4
using namespace std;

int dp[1005][1005];	//dp[考慮1~i的長度][現在所在狀態(字尾狀態)]=min改變次數 
int h[300];

struct Trie{
	int next[1005][MAX_ALPHA];	//next[狀態(的代號)][如果吃到'此'alpha]=轉移到的下一個狀態 
	int fail[1005];		//fail[狀態]=fail到的狀態 
	bool end[1005]; 	//是否是終止狀態(此題為瑕疵基因) 
	int root;			//root的狀態代號
	int L;				//狀態個數(不包括root) 
	 
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
				a) 如果now->next[i]為NULL，那麼將now->next[i]指向now的失敗指針的i號子結點, 
				即now->next[i] = now->fail->next [i];
				*/
				
				else{
					fail[next[now][i]]=_fail;
					end[next[now][i]]|=end[_fail];
					que.push(next[now][i]);
				}
				/*
				b) 如果now->next[i]不等於NULL，則需要構造now->next[i]的失敗指針，由於a)的操作，
				我們知道now的失敗指針一定存在一個i號子結點，即now->fail->next[i]，
				那麼我們將now->next[i]的失敗指針指向它，即now->next[i]->fail = now->fail->next[i]；
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
		dp[0][0]=0;		//[字串長度為零][狀態為'其他'] 
		
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
