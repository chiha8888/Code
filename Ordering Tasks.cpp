#include<bits/stdc++.h>
using namespace std;
int indeg[105];
int used[105][105];
/*
5 4
1 2
2 3
1 3
1 5
0 0
*/
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0)
			return 0;
		memset(indeg,0,sizeof(indeg));
		memset(used,0,sizeof(used));
		vector<int> edge[105];
		int x,y;
		for(int i=0;i<m;i++){
			cin>>x>>y;
			if(used[x][y]==0&&x!=y){
				edge[x].push_back(y);
				indeg[y]++;
				used[x][y]=1;
			}
		}
		queue<int> que;
		vector<int> ans;
		for(int i=1;i<=n;i++){
			if(indeg[i]==0)
				que.push(i);	
		}
		for(int i=1;i<=n;i++){
			if(que.empty())
				break;
			int k=que.front();	que.pop();
			//ans.push_back(k);
			cout<<k<<" ";
			for(int j=0;j<edge[k].size();j++){
				if(--indeg[edge[k][j]]==0)
					que.push(edge[k][j]);
			}
		}
		cout<<endl;
		
		if(ans.size()==n){
			cout<<ans[0];
		for(int i=1;i<n;i++)
			cout<<" "<<ans[i];
		cout<<endl;
		}
		
		
	}	
	return 0;	
} 
