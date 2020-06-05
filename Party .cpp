#include<bits/stdc++.h>
using namespace std;
vector<int> edge[2005];
bool used[2005];
int n;
int ans;
/*
5
-1
1
2
1
-1
*/
void dfs(int level,int people){
	ans=max(ans,level);
	used[people]=true;
	for(int i=0;i<edge[people].size();i++){
		dfs(level+1,edge[people][i]);
	}
}
int main(){
	cin>>n;
	int x;		
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==-1)
			continue;
		edge[x].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			dfs(1,i);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
