#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int N,M,Q;
int A[505][505];
int dp[505][505];
//dp[i][j]: form i to j , the number of car in it
//d[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+A[i][j]
int main(){
	cin>>N>>M>>Q;
	int left,right;
	for(int i=0;i<M;i++){
		cin>>left>>right;
		A[left][right]++;
	}
	for(int i=1;i<=N;i++)
		dp[i][i]=A[i][i];
	for(int i=N-1;i>=1;i--){
		for(int j=i+1;j<=N;j++){
			dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+A[i][j];
		}
	}
	
	int p,q;
	for(int i=0;i<Q;i++){
		cin>>p>>q;
		cout<<dp[p][q]<<endl;	
	} 
	return 0;
} 
