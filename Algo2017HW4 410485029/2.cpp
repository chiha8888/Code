#include<bits/stdc++.h>
using namespace std;
/*
5 9
1 2 10
1 3 3
2 3 1
2 4 2
3 2 4
3 4 8
3 5 2
4 5 7
5 4 9
1
*/
struct _edge{
	_edge(int t,float c){
		to=t;
		cost=c;
	}
	int to;
	float cost;
};
int n,m,s;
vector<_edge> edge[55];
bool used[55];
float d[55];
int parent[55];

void dijkstra(){
	memset(d,0x66,sizeof(d));
	memset(used,0,sizeof(used));
	d[s]=0;
	parent[s]=0;
	priority_queue<pair<float,int>,vector<pair<float,int> >,greater<pair<float,int> > > que;
	que.push(pair<float,int>(0.0,s));
	while(!que.empty()){
		pair<float,int> p=que.top(); que.pop();
		float dis=p.first;
		int nowp=p.second;
		if(used[nowp]||d[nowp]>dis)
			continue;
		for(int i=0;i<edge[nowp].size();i++){
			_edge e=edge[nowp][i];
			if(!used[e.to]&&d[e.to]>dis+e.cost){
				d[e.to]=dis+e.cost;
				parent[e.to]=nowp;
				que.push(pair<float,int>(d[e.to],e.to));
			}
		}
	}
	return ;
}

int main(){
	cin>>n>>m;
	int a,b;
	float w;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>w;
		edge[a].push_back(_edge(b,w)); 
	}
	cin>>s;
	dijkstra();
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<parent[i]<<" ";
	cout<<endl;
	
	return 0;
} 
