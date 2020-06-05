#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string.h>
using namespace std;
const int INF=100000000;
int N,M;
int dp[2005][2005];
//dp[i][j]=change i~jth subsequence to palindrome minimum cost
char s[2005];
int cost[30];	//0:'a'  
 
int main(){
	cin>>N>>M;
	for(int i=1;i<=M;i++)
		cin>>s[i];
	char c; int a,b;
	for(int i=0;i<30;i++)
		cost[i]=INF;
	for(int i=1;i<=N;i++){
		cin>>c>>a>>b;
		cost[c-'a']=min(a,b);
	}
	for(int i=M-1;i>=1;i--){
		for(int j=i+1;j<=M;j++){
			if(s[i]==s[j])
				dp[i][j]=dp[i+1][j-1];	
			else
				dp[i][j]=min(dp[i][j-1]+cost[s[j]-'a'],dp[i+1][j]+cost[s[i]-'a']);
		}
	}
	/*for(int i=0;i<=M;i++){
		for(int j=0;j<=M;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/	
	cout<<dp[1][M]<<endl; 
	
	return 0;
} 
