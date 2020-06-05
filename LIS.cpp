#include<bits/stdc++.h>
using namespace std;
int a[1005];
int dp[1005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	fill(dp,dp+n,1e9);
	
	for(int i=0;i<n;i++){
		*lower_bound(dp,dp+n,a[i])=a[i];	
	}
	cout<<lower_bound(dp,dp+n,1e9)-dp<<endl;
	return 0;
} 
