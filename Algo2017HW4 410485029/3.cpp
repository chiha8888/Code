#include<bits/stdc++.h>
using namespace std;
/*
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -3
1
*/
int n,m,s;
struct _edge{
	_edge(int t,float c){
		to=t;
		cost=c;
	}
	int to;
	float cost;
};
vector<_edge> edge[55];
float d[55];
int parent[55];
bool negative_cycle;

void bellman_ford(){
	fill(d,d+55,100000000);
	negative_cycle=false;
	d[s]=0;
	for(int k=1;k<n;k++){	//n-1 times
		for(int i=1;i<=n;i++){	//E
			for(int j=0;j<edge[i].size();j++){
				_edge e=edge[i][j];
				if(d[i]!=100000000&&d[i]+e.cost<d[e.to]){
					d[e.to]=d[i]+e.cost;
					parent[e.to]=i;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<edge[i].size();j++){
			_edge e=edge[i][j];
			if(d[i]+e.cost<d[e.to]){
				negative_cycle=true;
				return ;
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
	bellman_ford();
	if(negative_cycle)
		cout<<"There is a negative weight cycle in the graph"<<endl;
	else{
		for(int i=1;i<=n;i++)
			cout<<d[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++)
			cout<<parent[i]<<" ";
		cout<<endl;
	}
	
	return 0;
} 
