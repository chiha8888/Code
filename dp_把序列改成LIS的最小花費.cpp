#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int A[2005];
int Sort[2005];
int dp[2005][2005];
//dp[i][j]: consider 1~i,ending with jth big number minimum cost
//dp[i][j]=min(dp[i-1][k])+abs(A[i]-Sort[j])  (1<=k<=j)
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		Sort[i]=A[i];
	}	
	sort(Sort+1,Sort+1+n);
	
	//increasing
	for(int i=1;i<=n;i++)
		dp[1][i]=abs(A[1]-Sort[i]);
	for(int i=2;i<=n;i++){
		int mini=dp[i-1][1];
		for(int j=1;j<=n;j++){
			mini=min(mini,dp[i-1][j]);
			dp[i][j]=mini+abs(A[i]-Sort[j]);
		}
	}
	int ans=0x7fffffff;
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[n][i]);
	}
	//decreaing (reverse)
	reverse(A+1,A+1+n);
	for(int i=1;i<=n;i++)
		dp[1][i]=abs(A[1]-Sort[i]);
	for(int i=2;i<=n;i++){
		int mini=dp[i-1][1];
		for(int j=1;j<=n;j++){
			mini=min(mini,dp[i-1][j]);
			dp[i][j]=mini+abs(A[i]-Sort[j]);
		}
	} 
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[n][i]);
	}
	
	cout<<ans<<endl;
	
	return 0;
} 
