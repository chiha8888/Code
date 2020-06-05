#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
//POJ 2139 
int d[305][305];
int kstar[305];
int N,M;
void FW(){
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main(){
	cin>>N>>M;
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<305;i++)
		d[i][i]=0;
	int k;
	for(int i=0;i<M;i++){
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>kstar[i];
		}
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				d[kstar[i]][kstar[j]]=d[kstar[j]][kstar[i]]=1;
			}
		}
	}
	FW();
	int mini=0x7fffffff;
	for(int i=1;i<=N;i++){
		int sum=0;
		for(int j=1;j<=N;j++){
			sum+=d[i][j];
		}
		mini=min(mini,sum);
	}
	cout<<mini*100/(N-1)<<endl;		//	important 
	
	return 0;
} 
