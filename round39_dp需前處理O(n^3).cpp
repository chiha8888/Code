#include<bits/stdc++.h>
using namespace std;
int n,m,k,mm;
int s[505][505];	//s[��i��][��j�����|]=min�b�Ǯժ��ɶ� 
int dp[505][505];	//dp[�Ҽ{1~i��][��j�����|]=min�b�Ǯժ��ɶ� 

int main(){
	cin>>n>>m>>k;
	
	//�w�B�z 
	vector<int> vec;
	char yn;
	for(int i=1;i<=n;i++){
		vec.clear();
		for(int j=0;j<m;j++){
			cin>>yn;
			if(yn=='1'){
				vec.push_back(j);
			}	
		}
		int tot=vec.size();	//�`�@�X���
		for(int j=0;j<=k;j++){	//��j�����| 
			if(j>=tot){
				s[i][j]=0;
				continue;
			}
			mm=100000000;
			for(int c=0;c<=j;c++){	//�e�q��c�����|�A�᭱��j-c�����| 
				mm=min(mm,abs(vec[tot-1-(j-c)]-vec[c]+1));
			}
			s[i][j]=mm;
		} 
	}
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	//dp O(n*k^2)
	memset(dp,0x6f,sizeof(dp));
	for(int i=0;i<=k;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int c=0;c<=j;c++){
				dp[i][j]=min(dp[i][j],dp[i-1][j-c]+s[i][c]);
			}
		}
	}
	
	int ans=100000000;
	for(int i=0;i<=k;i++){
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
} 
