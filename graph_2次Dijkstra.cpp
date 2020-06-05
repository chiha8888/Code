#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
//POJ 3268
typedef pair<int,int> P;
const int INF=1e9;
int d1[1005];	//to
int d2[1005];	//back
int N,M,X;

struct E{
	int to;
	int cost;
};
vector<E> edge1[1005];	
vector<E> edge2[1005];	

void Dijkstra(){
	priority_queue<P,vector<P>,greater<P> > q;
	fill(d1+1,d1+1+N,INF);	fill(d2+1,d2+1+N,INF);
	d1[X]=d2[X]=0;
	q.push(P(0,X));
	//back
	while(!q.empty()){
		P p=q.top(); q.pop();
		int v=p.second;
		if(d1[v]<p.first)
			continue;
		for(int i=0;i<edge1[v].size();i++){
			E e=edge1[v][i];
			if(d1[v]+e.cost<d1[e.to]){
				d1[e.to]=d1[v]+e.cost;
				q.push(P(d1[e.to],e.to));
			}
		}
	}
	//to
	q.push(P(0,X));
	while(!q.empty()){
		P p=q.top(); q.pop();
		int v=p.second;
		if(d2[v]<p.first)
			continue;
		for(int i=0;i<edge2[v].size();i++){
			E e=edge2[v][i];
			if(d2[v]+e.cost<d2[e.to]){
				d2[e.to]=d2[v]+e.cost;
				q.push(P(d2[e.to],e.to));
			}
		}
	}
	
}

int main(){
	cin>>N>>M>>X;
	int a,b,t;
	E e;
	for(int i=0;i<M;i++){
		cin>>a>>b>>t;
		e.to=b;	e.cost=t;
		edge2[a].push_back(e);
		e.to=a;
		edge1[b].push_back(e); 
	} 
	Dijkstra();
	int ans=0;
	for(int i=1;i<=N;i++){
		ans=max(ans,d1[i]+d2[i]);
	}
	cout<<ans<<endl;
	
	return 0;
} 
