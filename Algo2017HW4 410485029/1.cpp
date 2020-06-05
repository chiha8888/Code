#include<bits/stdc++.h>
using namespace std;
struct _edge{
	_edge(int t,float c){
		to=t;
		cost=c;
	} 
	int to;
	float cost;
};
vector<_edge> edge[55];
bool used[55];
float mincost[55];
int parent[55];
int n,m,root;

float prim(){
	float res=0;
	memset(mincost,0x66,sizeof(mincost));
	memset(used,0,sizeof(used));
	mincost[root]=0;
	parent[root]=0;
	priority_queue<pair<float,int>,vector<pair<float,int> >,greater<pair<float,int> > > que;
	que.push(pair<float,int>(0.0,root));
	while(!que.empty()){
		pair<float,int> p=que.top(); que.pop();
		float dis=p.first;
		int nowp=p.second;
		if(used[nowp]||mincost[nowp]<dis)
			continue;
		used[nowp]=true;
		res+=dis;
		for(int i=0;i<edge[nowp].size();i++){
			_edge e=edge[nowp][i];
			if(!used[e.to]&&mincost[e.to]>e.cost){
				mincost[e.to]=e.cost;
				parent[e.to]=nowp;
				que.push(pair<float,int>(e.cost,e.to));
			} 
		}
	}
	return res;
}

int main(){
	cin>>n>>m;
	int a,b;
	float w;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>w;
		edge[a].push_back(_edge(b,w));
		edge[b].push_back(_edge(a,w));
	}		
	cin>>root;
	

	float ans=prim();
	for(int i=1;i<=n;i++){
		cout<<parent[i]<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
	return 0;
} 
