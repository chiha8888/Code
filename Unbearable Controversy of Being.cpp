#include<bits/stdc++.h>
using namespace std;
vector<int> edge[3005];
bool _edge[3005][3005];
vector<int>::iterator iter;
int ans;

int main(){
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		edge[x].push_back(y);
		_edge[x][y]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				int r=0;
				for(int k=0;k<edge[i].size();k++){
					if(edge[i][k]!=j&&edge[i][k]!=i&&_edge[edge[i][k]][j])
						r++;
				}
				ans+=r*(r-1)/2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
