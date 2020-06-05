#include<bits/stdc++.h>
using namespace std;
int a[100005];
int m[100005];
int dp[100005];
/*
3
3 5 8
3 2 2
17
*/
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	int k;
	cin>>k;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++){
			if(dp[j]>=0)
				dp[j]=m[i];
			else if(j-a[i]<0||dp[j-a[i]]<=0)
				dp[j]=-1;
			else
				dp[j]=dp[j-a[i]]-1;		
		}
	}
	if(dp[k]>=0)
		cout<<"Yes"<<endl;
	else 
		cout<<"No"<<endl;
		
	return 0;
} 
