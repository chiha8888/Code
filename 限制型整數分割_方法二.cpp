#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
int const SIZE=1000005;
ll const mod=1000000000;
ll dp[SIZE];

int main(){
	dp[0]=1;
	for(int i=1;i<=1000000;i++){
		if(i&1)
			dp[i]=dp[i-1];
		else{
			if(dp[i-1]+dp[i>>1]>=mod)
				dp[i]=dp[i-1]+dp[i>>1]-mod;
			else
				dp[i]=dp[i-1]+dp[i>>1];
		}		
	}
	
	int num;
	cin>>num;
	cout<<dp[num]<<endl;
	return 0;
} 
