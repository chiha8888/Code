#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int dp[1005][35][2];	
//dp[i][j][k]:consider 1~i minutes,using j times of chane,and currently at k position's maximum eating number
int T,W;
int fall[1005];
//POJ 2385
int main(){
	cin>>T>>W;
	for(int i=1;i<=T;i++)
		cin>>fall[i];
	if(fall[1]==1)
		dp[1][0][0]=1;
	else
		dp[1][1][1]=1;
	for(int i=2;i<=T;i++){
		for(int j=0;j<=W;j++){
			for(int k=0;k<=1;k++){
				if(j-1>=0)
					dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-1][(k+1)&1])+((fall[i]-1==k)?1:0);
				else
					dp[i][j][k]=dp[i-1][j][k]+((fall[i]-1==k)?1:0);
			}
		}
	}	
	/*for(int i=0;i<=T;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j][0]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<=T;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j][1]<<" ";
		}
		cout<<endl;
	}*/
	int res=0;
	for(int i=0;i<=W;i++){
		for(int j=0;j<=1;j++){
			res=max(res,dp[T][i][j]);
		}
	}
	cout<<res<<endl;
	
	return 0;
}
