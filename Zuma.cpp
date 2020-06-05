#include<bits/stdc++.h>

using namespace std;
int c[505];
int dp[505][505];
/*
7
1 4 4 2 3 2 1
*/

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	//ini
	dp[0][0]=1;
	dp[n-1][n-1]=1;
	if(n-2>=0){
		dp[n-2][n-2]=1;
		dp[n-2][n-1]=(c[n-2]==c[n-1])?1:2;
	}
	for(int i=n-3;i>=0;i--){
		for(int j=1;j<n;j++){
			if(i==j)
				dp[i][j]=1;
			else if(i>j)
				dp[i][j]=0;
			else{	//i<j
				dp[i][j]=1+dp[i+1][j];
				for(int k=i+2;k<=j;k++){
					if(c[i]==c[k]){
						dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j]);
					}
				}
				if(c[i]==c[i+1])
					dp[i][j]=min(dp[i][j],1+dp[i+2][j]);

			}
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<dp[0][n-1]<<endl;	
	return 0;
} 
