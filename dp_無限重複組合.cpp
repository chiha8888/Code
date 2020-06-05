#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;	// > < > < hahaha,bigint
const ll floor=1e18;
int N,K;
ll dplow[105][1005];
ll dpup[105][1005];
//dp[i][j]: consider 1~i to build up j's maximum number of ways
int main(){
	cin>>N>>K;
	for(int i=0;i<=K;i++)
		dplow[i][0]=1;
	for(int i=1;i<=K;i++){
		for(int j=1;j<=N;j++){
			if(j-i>=0){
				dplow[i][j]=(dplow[i-1][j]+dplow[i][j-i])%floor;
				dpup[i][j]=dpup[i-1][j]+dpup[i][j-i]+(dplow[i-1][j]+dplow[i][j-i])/floor;
			}	
			else{
				dplow[i][j]=dplow[i-1][j];
				dpup[i][j]=dpup[i-1][j];
			}
		}
	}
	if(dpup[K][N])
		printf("%lld%018lld\n",dpup[K][N],dplow[K][N]);
	else
		cout<<dplow[K][N]<<endl;	
	
	return 0;
} 
