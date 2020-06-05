#include<bits/stdc++.h>
using namespace std;
int dp[12][105][105];
int main(){
	int n,q,c;
	cin>>n>>q>>c;
	int x,y,s;
	for(int i=0;i<n;i++){
		cin>>x>>y>>s;
		dp[s][x][y]++;
	}
	for(int k=0;k<=c;k++){
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				dp[k][i][j]+=dp[k][i-1][j]+dp[k][i][j-1]-dp[k][i-1][j-1];
			}
		}
	}
	int t,x1,y1,x2,y2;
	for(int i=0;i<q;i++){
		int ans=0;
		cin>>t>>x1>>y1>>x2>>y2;
		for(int j=0;j<=c;j++){
			int count=dp[j][x2][x2]-dp[j][x2][y1-1]-dp[j][x1-1][y2]+dp[j][x1-1][y1-1];
			ans+=((j+t)%(c+1))*count;
		}
		cout<<ans<<endl;
	}
	return 0;
}
