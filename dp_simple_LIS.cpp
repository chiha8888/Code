#include<iostream> 
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
const int INF=1e8;
int A[40005];
int dp[40005];

int main(){
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		memset(dp,0x7f,sizeof(int)*(n+1));
		//LIS
		for(int i=0;i<n;i++){
			*lower_bound(dp,dp+n,A[i])=A[i]; 
		}
		int ans=lower_bound(dp,dp+n+1,0x7f7f7f7f)-dp;
		cout<<ans<<endl;
	}
	
}
