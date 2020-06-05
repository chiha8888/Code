#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> P;
const int INF=1e9;
struct E{
	int to;
	int cost;
};
vector<E> edge[1005];
bool used[1005];
int mincost[1005];

int prim(){
	int res=0;
	memset(used,0,sizeof(used));
	fill(mincost,mincost+1005,INF);
	priority_queue<P,vector<P>,greater<P> > pq;
	pq.push(P(0,1));
	mincost[1]=0;
	while(!pq.empty()){
		P p=pq.top(); pq.pop();
		int v=p.second;
		if(used[v]||mincost[v]<p.first)
			continue;
		used[v]=true;
		res+=p.first;
		for(int i=0;i<edge[v].size();i++){
			E e=edge[v][i];
			if(e.cost<mincost[e.to]){
				mincost[e.to]=e.cost;
				pq.push(P(mincost[e.to],e.to));
			}
		}
	}
	return res;	
}

int main(){
	int N,M;
	int a,b,c;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		E e;
		e.to=b;	e.cost=-1*c;
		edge[a].push_back(e);
		e.to=a;
		edge[b].push_back(e);
	}
	int ans=-1*prim();
	for(int i=1;i<=N;i++){
		if(!used[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
