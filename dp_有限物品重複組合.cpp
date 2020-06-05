#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int mod=1e6;
int T,A,S,B;
int dp[2][100005];
int N[1005];

int main(){
	cin>>T>>A>>S>>B;
	int k;
	for(int i=0;i<A;i++){
		cin>>k;
		N[k]++;
	}
	dp[0][0]=1;
	dp[1][0]=1;
	for(int i=1;i<=T;i++){
		for(int j=1;j<=A;j++){
			if(j-N[i]-1>=0)
				dp[i&1][j]=(dp[i&1][j-1]+dp[(i-1)&1][j]-dp[(i-1)&1][j-N[i]-1]+mod)%mod;
			else
				dp[i&1][j]=(dp[i&1][j-1]+dp[(i-1)&1][j])%mod;
		}
	}
	
	/*for(int i=0;i<2;i++){
		for(int j=0;j<=A;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int ans=0;
	for(int i=S;i<=B;i++){
		ans=(ans+dp[T&1][i])%mod;
	}
	cout<<ans<<endl;
	
	return 0;
}
