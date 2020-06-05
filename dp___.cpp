#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[2][10005];
int main(){
	int T;
	string s1,s2;
	int l1,l2;
	cin>>T;
	while(T--){
		cin>>s1>>s2;
		l1=s1.length();	l2=s2.length();
		//init
		dp[0][0]=1;
		bool find=false;
		int t=0,ch=0;
		for(int i=1;i<=l1;i++){
			dp[0][i]=i;
		//	cout<<dp[0][i]<<' ';
			if(s1[i-1]==s2[0]&&ch==0)t=i,ch=1;
		}
		
	//	cout<<t<<endl;
		for(int i=t;i<=l1;i++){
			dp[0][i]--;//cout<<dp[0][i]<<' ';
		}

		for(int i=2;i<=l2;i++){
			dp[i&1][0]=i;
			for(int j=1;j<=l1;j++){
				if(s2[i-1]==s1[j-1])dp[i&1][j]=dp[(i-1)&1][j-1];
				else dp[i&1][j]=min(dp[(i-1)&1][j]+1,min(dp[(i-1)&1][(j-1)]+1,dp[i&1][(j-1)]+1));
				//cout<<dp[i&1][j]<<' ';
			}
			//cout<<endl;
		}
		cout<<dp[l2&1][l1]<<"\n";	
	}
	
	return 0;
} 
