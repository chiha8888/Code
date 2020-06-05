#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[2][1<<15];
int _map[15][15];
/*
3 3
...
.x.
...
*/
int main(){
	cin>>n>>m;
	char c;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c;
			if(c=='.')
				_map[i][j]=0;
			else
				_map[i][j]=1;	
		}
	}
	dp[0][(1<<m)-1]=1;
	int cur=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cur^=1;
			for(int s=0;s<(1<<m);s++){	//枚舉這次狀態 
				if(_map[i][j]||(s>>j)&1){	//障礙物上方必須為1 
					dp[cur][s]+=dp[cur^1][s&(1<<j)];
				}
				else{
					if(!((s>>j)&1)){
						
					}
				}
			}
			for(int p=0;p<(1<<m);p++)
				cout<<dp[cur][p]<<"\t";
			cout<<endl;
		}
	}
	cout<<dp[cur][(1<<m)-1]<<endl;
	return 0;	
} 
