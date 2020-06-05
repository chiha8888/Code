#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
//POJ 2184
const int INF=1e9;
int dp[2][200005];
int c[2][200005];
int s[105];
int f[105];

int main(){
	int N;
	int a,b;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a>>b;
		s[i]=a;
		f[i]=b+1000;
	}		
	//init
	for(int i=0;i<=2000*N;i++){
		dp[0][i]=-INF;
		c[0][i]=0;
	}
	dp[0][0]=0;
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<=2000*N;j++){
			dp[i&1][j]=dp[(i-1)&1][j];
			c[i&1][j]=c[(i-1)&1][j];
			if(j-f[i]>=0&&dp[(i-1)&1][j-f[i]]!=-INF&&dp[(i-1)&1][j-f[i]]+s[i]>dp[(i-1)&1][j]){
				dp[i&1][j]=dp[(i-1)&1][j-f[i]]+s[i];
				c[i&1][j]=c[(i-1)&1][j-f[i]]+1;
			}
		}
	}
	
	int ans=0;
	for(int j=1;j<=2000*N;j++){
		if(dp[N&1][j]>=0&&j-c[N&1][j]*1000>=0)
			ans=max(ans,dp[N&1][j]+(j-c[N&1][j]*1000)); 
	}
	cout<<ans<<endl;
	return 0;
} 
