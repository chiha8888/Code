#include<bits/stdc++.h>
using namespace std;

long long dp[505][505];
int queries[100005];

int main(){
	char map[505][505];
	int h,w,n;
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>map[i][j];
		}
	}
	//init
	memset(dp,0,sizeof(dp));
	for(int j=1;j<w;j++){
		dp[0][j]+=dp[0][j-1];
		if(map[0][j]=='.'&&map[0][j-1]=='.')
			dp[0][j]++;
	}
	for(int i=1;i<h;i++){
		dp[i][0]+=dp[i-1][0];
		if(map[i][0]=='.'&&map[i-1][0]=='.')
			dp[i][0]++;
	}
	//calc
	for(int i=1;i<h;i++){
		for(int j=1;j<w;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			if(map[i][j]=='.'){
				if(map[i-1][j]=='.')
					dp[i][j]++;
				if(map[i][j-1]=='.')
					dp[i][j]++;
			}
		}
	}
	
	int r1,c1,r2,c2;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r1>>c1>>r2>>c2;
		r1--;c1--;r2--;c2--;
		long long answer=0;
		answer=dp[r2][c2]-((c1-1>=0)?dp[r2][c1-1]:0)-((r1-1>=0)?dp[r1-1][c2]:0)+((r1-1>=0&&c1-1>=0)?dp[r1-1][c1-1]:0);
		for(int j=r1;j<=r2;j++){
			if(c1-1>=0&&map[j][c1-1]=='.'&&map[j][c1]=='.')
				answer--;
		}
		for(int j=c1;j<=c2;j++){
			if(r1-1>=0&&map[r1-1][j]=='.'&&map[r1][j]=='.')
				answer--;
		}
		cout<<answer<<endl;
	}
	return 0;
} 
