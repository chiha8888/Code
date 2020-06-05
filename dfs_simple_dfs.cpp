#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
char A[25][25];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int W,H;
int ans;

void dfs(int x,int y){
	A[x][y]='@';
	ans++;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&nx<H&&ny>=0&&ny<W&&A[nx][ny]=='.'){
			dfs(nx,ny);
		}
	}	
}

int main(){
	while(cin>>W>>H){
		if(W==0&&H==0)
			break;
		int sx,sy;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				cin>>A[i][j];
				if(A[i][j]=='@'){
					sx=i; sy=j;	
				}
			}
		}
		ans=0;
		dfs(sx,sy);
		cout<<ans<<endl;
	}
	return 0;
} 
