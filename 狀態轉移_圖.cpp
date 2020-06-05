#include<bits/stdc++.h>
using namespace std;
int t[10]; 	//ó布 
double dp[1<<10][35];	//搐Τó布i,┮竚j
double edge[35][35]; 	//禯瞒 
/*
2 4 2 1
3 1
4
1 4 2
1 3 3
2 4 5
2 3 3
*/ 
int main(){
	int n,m,a,b;	//nó布计,mカ计,a癬翴,b沧翴
	cin>>n>>m>>a>>b;
	for(int i=0;i<n;i++)
		cin>>t[i];
	int e;	//瓜娩 
	cin>>e;	
	int x,y,w;
	for(int i=0;i<e;i++){
		cin>>x>>y>>w;
		x--; y--;
		edge[x][y]=w;
		edge[y][x]=w;
	}
	
	for(int i=0;i<1<<n;i++)
		fill(dp[i],dp[i]+m,1000000000);
	
	dp[(1<<n)-1][a-1]=0;
	for(int s=(1<<n)-1;s>=0;s--){
		for(int v=0;v<m;v++){
			for(int i=0;i<n;i++){	//ノ材i眎ó布 
				if((s>>i)&1){	//狦硂眎ó布ノ 
					for(int j=0;j<m;j++){	
						if(edge[v][j]>0){	//v->jΤ娩 
							dp[s&~(1<<i)][j]=min(dp[s&~(1<<i)][j],dp[s][v]+edge[v][j]/t[i]);
						}
					}
				}
			}
		}
	}
	double ans=1000000000;
	for(int i=0;i<1<<n;i++){
		ans=min(ans,dp[i][b-1]);
	} 
	if(ans==1000000000)
		cout<<"Impossible"<<endl;
	else
		printf("%.3lf\n",ans);
	return 0;
} 
