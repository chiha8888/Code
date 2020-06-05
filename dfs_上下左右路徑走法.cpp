#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int W,H,mini;
int A[25][25];
//POJ 3009

void dfs(int d,int x,int y){
	if(d>10)
		return;
	//up
	for(int i=x-1;i>=0;i--){
		if(A[x-1][y]==1)
			break;
		if(A[i][y]==3){
			mini=min(mini,d);
			return;
		}
		if(A[i][y]==1){
			A[i][y]=0;
			dfs(d+1,i+1,y);
			A[i][y]=1;
			break;
		}
	}
	//down
	for(int i=x+1;i<H;i++){
		if(A[x+1][y]==1)
			break;
		if(A[i][y]==3){
			mini=min(mini,d);
			return;
		}
		if(A[i][y]==1){
			A[i][y]=0;
			dfs(d+1,i-1,y);
			A[i][y]=1;
			break;
		}
	}
	//right
	for(int i=y+1;i<W;i++){
		if(A[x][y+1]==1)
			break;
		if(A[x][i]==3){
			mini=min(mini,d);
			return;
		}
		if(A[x][i]==1){
			A[x][i]=0;
			dfs(d+1,x,i-1);
			A[x][i]=1;
			break; 
		} 
	}
	//left
	for(int i=y-1;i>=0;i--){
		if(A[x][y-1]==1)
			break;
		if(A[x][i]==3){
			mini=min(mini,d);
			return;
		}
		if(A[x][i]==1){
			A[x][i]=0;
			dfs(d+1,x,i+1);
			A[x][i]=1;
			break;
		}	
	}
	
	return;
}

int main(){
	int sx,sy;
	while(cin>>W>>H){
		if(W==0&&H==0)
			break;
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++){
				cin>>A[i][j];
				if(A[i][j]==2){
					sx=i; sy=j;
				}
			}
		mini=100;
		dfs(1,sx,sy);
		if(mini==100)
			cout<<-1<<endl;
		else
		 	cout<<mini<<endl;
	}
	
	return 0;
} 
