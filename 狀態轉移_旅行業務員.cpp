#include<bits/stdc++.h>
using namespace std;
int edge[15][15]; 
int dp[1<<15][15];
/*
5 8
0 1 3
1 2 5
2 0 4
2 3 5
3 4 3
4 0 7
4 1 6
0 3 4
*/
int main(){
	int n,m; //n個點,m條邊 
	cin>>n>>m;
	int x,y,z;
	memset(edge,0x33,sizeof(edge));
	for(int i=0;i<m;i++){
		cin>>x>>y>>z;
		edge[x][y]=z;
	}
	memset(dp,0x33,sizeof(dp));
	dp[(1<<n)-1][0]=0;
	
	for(int i=(1<<n)-2;i>=0;i--){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(!((i>>k)&1)){
					dp[i][j]=min(dp[i][j],dp[i|(1<<k)][k]+edge[j][k]);
				}
			}			
		}
	}
	
	cout<<dp[0][0]<<endl;
} 
