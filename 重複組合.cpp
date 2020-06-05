#include<bits/stdc++.h>
using namespace std;
int a[1005];
int dp[1005][1005];
/*
3
3
1 2 3
10000
*/
int main(){
	int n,m,M;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>M;
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			dp[i+1][j]=dp[i][j];
			if(j-1>=0)
				dp[i+1][j]+=dp[i+1][j-1];
			if(j-a[i]-1>=0)
				dp[i+1][j]-=dp[i][j-a[i]-1];
			dp[i+1][j]%=M;
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
} 
