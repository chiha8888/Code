#include<bits/stdc++.h>
using namespace std;
int color[15][15];
int n,m,M;
int used[15][15];
/*
3 3 1000000
...
.x.
...
*/
int rec(int i,int j){
	if(j==m){
		return rec(i+1,0);
	}	
	if(i==n){
		return 1;
	}
	if(color[i][j]||used[i][j]){
		return rec(i,j+1);
	}
	int re=0;
	used[i][j]=1;
	if(!color[i][j+1]&&!used[i][j+1]&&j+1<m){	//¾îµÛ 
		used[i][j+1]=1;
		re+=rec(i,j+2);
		used[i][j+1]=0;
	}
	if(!color[i+1][j]&&!used[i+1][j]&&i+1<n){	//ª½µÛ 
		used[i+1][j]=1;
		re+=rec(i,j+1);
		used[i+1][j]=0;
	}
	used[i][j]=0;
	
	return re%M; 
}

int main(){
	cin>>n>>m>>M;
	char c;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c;
			if(c=='.')
				color[i][j]=0;
			else
			 	color[i][j]=1;	
		}
	}
	cout<<rec(0,0)<<endl;	
	
} 
