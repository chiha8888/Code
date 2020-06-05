#include<bits/stdc++.h>
using namespace std;
long long input[100005];
long long a[100005];
long long dp[2][100005];
long long ans;
/*
4
1 5 4 7
*/
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>input[i];
	for(int i=1;i<=n-1;i++){
		a[i]=abs(input[i-1]-input[i]);
	}
	
	for(int j=1;j<=n-1;j++){
		for(int i=0;i<2;i++){
			dp[i][j]=max(dp[(i+1)%2][j-1]+(long long)pow(-1,i)*a[j],(long long)pow(-1,i)*a[j]);
			ans=max(ans,dp[i][j]);
		}	
	}
	
	
	cout<<ans<<endl;
	return 0;
}
