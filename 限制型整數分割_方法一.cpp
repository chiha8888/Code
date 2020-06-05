#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll dp[1000005];	//dp[i][j]=j's method number,max element can be 2^i 
ll mod=1000000000; 
int main(){

	for(int i=0;i<1000005;i++)
		dp[i]=1;
	for(int i=1;i<20;i++){
		for(int j=1;j<1000005;j++){
			if(j-(int)pow(2.0,i)>=0){
				if(dp[j]+dp[j-(int)pow(2.0,i)]>=mod)
					dp[j]=dp[j]+dp[j-(int)pow(2.0,i)]-mod;
				else
					dp[j]=dp[j]+dp[j-(int)pow(2.0,i)];
			}
		}
	}
	int num;
	cin>>num;
	cout<<dp[num]<<endl;
	
	return 0;
} 
