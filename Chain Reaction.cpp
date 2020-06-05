#include<bits/stdc++.h>
using namespace std;
int d[1000005];
int dp[1000005];
int main(){
	int n;
	cin>>n;
	int a,b;
	int maxdis=-1;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		d[a]=b;	
		maxdis=max(maxdis,a);	
	}
	if(d[0])
		dp[0]=1;
	else
		dp[0]=0;
	for(int i=1;i<=maxdis;i++){
		if(!d[i])
			dp[i]=dp[i-1];
		else{//dp[i]:一定使用這個beacon所能達到的"最多" 
			if(i-d[i]-1>=0)
				dp[i]=dp[i-d[i]-1]+1;
			else
				dp[i]=1;	
		}
			
	}
	int ans=0;
	for(int i=0;i<=maxdis;i++){
		ans=max(ans,dp[i]);
	}
	cout<<n-ans<<endl;
	return 0;
} 
