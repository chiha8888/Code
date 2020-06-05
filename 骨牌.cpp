#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[2][1<<15];
/*
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
*/ 
int main(){
	while(cin>>n>>m){
		if(!n&&!m)
			return 0;
		memset(dp,0,sizeof(dp));
		dp[0][(1<<m)-1]=1;
		int cur=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cur^=1;
				memset(dp[cur],0,sizeof(dp[cur]));
				for(int s=0;s<(1<<m);s++){	//枚舉上次狀態 
					if((s>>j)&1){	//不放 
						dp[cur][s&~(1<<j)]+=dp[cur^1][s];
					}
					if(i&&(!((s>>j)&1))){	//放上面 
						dp[cur][s|(1<<j)]+=dp[cur^1][s];
					}
					if(j&&!((s>>(j-1))&1)&&((s>>j)&1)){	//放左邊 
						dp[cur][s|(1<<(j-1))]+=dp[cur^1][s];
					}
				}
			}	
		}
		cout<<dp[cur][(1<<m)-1]<<endl;
	}

	return 0;
} 
