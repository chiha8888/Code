#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
//dp[i][j]=dp[最多分成的組數i][總和=j]
/*
4
3
10000
*/
int main(){
	int n,m,M;
	cin>>n>>m>>M;
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++){
			if(j-i-1>=0)
				dp[i+1][j]=(dp[i][j]+dp[i+1][j-i-1])%M;
			else
				dp[i+1][j]=dp[i][j]%M;
		}
	}
	
	cout<<dp[m][n]<<endl;
	return 0;
} 
