#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
int dp[100005];
int a[105];
int c[105];


int main(){
	
	while(cin>>n>>m){
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>c[i];
		
		for(int i=1;i<=m;i++)
			 dp[i]=-1;
		dp[0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(dp[j]>=0)
					dp[j]=c[i];
				else if(j-a[i]>=0&&dp[j-a[i]]>=1)
					dp[j]=dp[j-a[i]]-1;
				else
					dp[j]=-1;
			}
		}
		
		int ans=0;
		for(int i=1;i<=m;i++){
			if(dp[i]>=0)
				ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
