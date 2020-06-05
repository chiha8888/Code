#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> P;
int const INF=1e9;
int edge[105][105];
int mincost[105];
bool used[105];
int N;
	
int Prim(){
	priority_queue<P,vector<P>,greater<P> > pq;
	fill(mincost,mincost+N,INF);
	fill(used,used+N,0);
	mincost[0]=0;
	int res=0;
	pq.push(P(0,0));
	while(!pq.empty()){
		P p=pq.top(); pq.pop();
		int v=p.second;
		if(used[v]||mincost[v]<p.first)	//used[v]: avoiding cycle
			continue;
		used[v]=true;
		res+=p.first;
		for(int i=0;i<N;i++){
			if(edge[v][i]<mincost[i]){
				mincost[i]=edge[v][i];
				pq.push(P(mincost[i],i));
			}
		}
	}
	return res;
}

int main(){
	while(cin>>N){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&edge[i][j]);
			}
		}
		cout<<Prim()<<endl;
	}
	
	return 0;
} 
