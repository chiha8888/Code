#include<bits/stdc++.h>
using namespace std;
struct edge{
	edge(int a,int b,int c){
		to=a; cap=b; rev=c;
	}
	int to;
	int cap;
	int rev;
};
vector<edge> vec[1000];
int level[1000];
int iter[1000];

void bfs(int s){
	memset(level,-1,sizeof(level));
	level[s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v=que.front();	que.pop();
		for(int i=0;i<vec[v].size();i++){
			edge &e=vec[v][i];
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}	
	}
}

int dfs(int s,int t,int f){
	if(s==t)
		return f;
	for(int &i=iter[s];i<vec[s].size();i++){
		edge &e=vec[s][i];
		if(e.cap>0&&level[s]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				vec[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
/*
5 7
0 1 10
0 2 2
1 2 6
1 3 6
3 2 3
2 4 5
3 4 8
0 4	
*/
//Dinic algo : O(V^2*E)
int main(){
	
	int n,m,s,t;	//s,t:起終點 
	cin>>n>>m;
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		vec[a].push_back(edge(b,c,vec[b].size()));
		vec[b].push_back(edge(a,0,vec[a].size()-1));			
	}
	cin>>s>>t;

	int flow=0;
	for(;;){		//最多執行V次 
		bfs(s);		//O(E)
		if(level[t]<0)
			break;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,100000000))>0){	//O(EV) 
			flow+=f;
		}
	}	
	cout<<flow<<endl;
	
	return 0;
} 
