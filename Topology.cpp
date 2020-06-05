#include<bits/stdc++.h>
using namespace std;
deque<int> d[55];
int indeg[55];
bool used[55];
int c;
/*
5 7
0 1
0 2
0 3
0 4
2 3
3 4
4 1
*/
/*
4 5
0 1
1 3
0 2
2 1
3 2
*/ 
int main(){
	int n,m,x,y;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		d[x].push_back(y);
		indeg[y]++;
	}
	queue<int> que;
	for(int i=0;i<n;i++){
		if(indeg[i]==0)
			que.push(i);
	} 
	for(int i=0;i<n;i++){
		if(que.empty())
			break;
		int v=que.front(); que.pop();
		cout<<v<<" ";
		for(int j=0;j<d[v].size();j++){
			if(--indeg[d[v][j]]==0)
				que.push(d[v][j]);
		}
	}
	cout<<endl;
	return 0;
} 
