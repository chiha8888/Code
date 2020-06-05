#include<bits/stdc++.h>
#define SIZE 10000
using namespace std;
vector<int> edge[SIZE];
bool check[SIZE][SIZE];
bool used[SIZE];
int indeg[SIZE];
int outdeg[SIZE];
bool _dfs[SIZE];
/*
5
0 1
1 4
4 5
5 6
6 0
*/
/*
5
0 1
1 4
4 5
7 6
6 7
*/
void dfs(int v){
	_dfs[v]=true;
	for(int i=0;i<edge[v].size();i++){
		if(!_dfs[edge[v][i]])
			dfs(edge[v][i]);
	}	
}

int main(){
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(!check[x][y]){
			edge[x].push_back(y);
			indeg[y]++; outdeg[x]++;
			used[x]=true; used[y]=true;
			check[x][y]=true;
		}
	}
	int nin=0,nout=0,neq=0,nall=0,start;
	for(int i=0;i<SIZE;i++)
		if(used[i])
			nall++; 
	for(int i=0;i<SIZE;i++){
		if(indeg[i]!=outdeg[i]){
			nall++;
			if(indeg[i]==outdeg[i]+1)
				nin++;
			else if(indeg[i]+1==outdeg[i]){
				nout++;
				start=i;
			}
			else{
				cout<<"can't find euler trail."<<endl;
				return 0;
			}
		}
		else{
			if(used[i])
				neq++;
		}
	}
	bool success=false;
	if(nin==0&&nout==0&&neq==nall)
		success=true;
	else if(nin==1&&nout==1&&neq==nall-2)
		success=true;
	else{
		cout<<"can't find euler trail."<<endl;
		return 0;
	}
		
	if(nout==1){
		dfs(start);
	}
	else{
		for(int i=0;i<SIZE;i++){
			if(used[i]){
				dfs(i);
				break;
			}
		}
	}
	for(int i=0;i<SIZE;i++){
		if(used[i]&&!_dfs[i])
			success=false;
	}
	if(success)
		cout<<"find euler trail."<<endl;
	else
	 	cout<<"can't find euler trail."<<endl;
	return 0;
} 
