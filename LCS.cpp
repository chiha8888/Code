# include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int main(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i+1]==t[j+1])
				dp[i+1][j+1]=dp[i][j]+1;
			else{
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}	
	cout<<dp[4][4]<<endl;
	return 0;
}
