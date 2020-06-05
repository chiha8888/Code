#include<bits/stdc++.h>
using namespace std;
string A[100005];
long long C[100005];
long long dp[100005][2];
 
int main(){
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>C[i];
	}
	for(int i=0;i<n;i++){
		cin>>A[i];	
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			dp[i][j]=1e15;
		}
	}
	dp[0][0]=0;
	dp[0][1]=C[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=1;j++){
			if(j==0){
				string re(A[i-1]);
				reverse(re.begin(),re.end());
				if(A[i]>=A[i-1])
					dp[i][0]=min(dp[i][0],dp[i-1][0]);
				if(A[i]>=re)
					dp[i][0]=min(dp[i][0],dp[i-1][1]);
			}
			if(j==1){
				string ren(A[i]);
				reverse(ren.begin(),ren.end());
				string rel(A[i-1]);
				reverse(rel.begin(),rel.end());
				if(ren>=A[i-1])
					dp[i][1]=min(dp[i][1],dp[i-1][0]+C[i]);
				if(ren>=rel)
					dp[i][1]=min(dp[i][1],dp[i-1][1]+C[i]);
			}
		}
	}
	
	long long answer=min(dp[n-1][0],dp[n-1][1]);
	if(answer==1e15)
		cout<<-1<<endl;
	else
	 	cout<<answer<<endl;
	return 0;
}
