#include<bits/stdc++.h>
using namespace std;
int n,m;
float d[55][55];

void floyd_warshall(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	} 
} 

int main(){
	cin>>n>>m;
	for(int i=1;i<55;i++){
		for(int j=1;j<55;j++){
			if(i==j)
				d[i][j]=0;
			else
				d[i][j]=100000000;
		}
	}
	int a,b;
	float w;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>w;
		d[a][b]=w;
	}
	floyd_warshall();
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j]==100000000)
				cout<<"N ";
			else
				cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
} 
