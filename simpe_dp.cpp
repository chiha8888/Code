#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int bowling[355][355];
int dp[355][355];

int main(){
	int n;	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>bowling[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+bowling[i][j];
		}
	}
	
	int res=0;
	for(int j=1;j<=n;j++)
		res=max(res,dp[n][j]);
	cout<<res<<endl;
	
	return 0;
} 
