#include<bits/stdc++.h>
using namespace std;
struct point{
	int x;
	int y;
	int d;
};
int n,m;
int sx,sy,ex,ey;
char a[1005][1005];
int d[1005][1005];
int used[2][1005][1005];
queue<point> que;
int c1[4]={-1,1,0,0};
int c2[4]={0,0,1,-1};

int main(){
	cin>>n>>m;
	char _a;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %c",&a[i][j]);
			d[i][j]=100000000;
		}
	}
	cin>>sx>>sy>>ex>>ey;
	que.push({sx,sy,1});
	que.push({sx,sy,2});
	d[sx][sy]=0;
	
	while(!que.empty()){
		point p=que.front();	que.pop();
		
		if(p.x==ex&&p.y==ey)
			break;
		if(p.d==1){	//¥ª¥k 
			//©¹¤W¤U
			for(int i=0;i<2;i++){
				int nextx=p.x+c1[i];
				int nexty=p.y+c2[i];
				if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&a[nextx][nexty]!='#'&&used[0][nextx][nexty]+used[1][nextx][nexty]<2){
					que.push({nextx,nexty,2});
					d[nextx][nexty]=d[p.x][p.y]+1;
					used[0][nextx][nexty]=1;
					
				}
			}
		}
		else if(p.d==2){
			for(int i=2;i<4;i++){

				int nextx=p.x+c1[i];
				int nexty=p.y+c2[i];
				if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&a[nextx][nexty]!='#'&&used[0][nextx][nexty]+used[1][nextx][nexty]<2){
					que.push({nextx,nexty,1});
					d[nextx][nexty]=d[p.x][p.y]+1;
					used[1][nextx][nexty]=1;
					
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	if(d[ex][ey]==100000000)
		cout<<-1<<endl;
	else
		cout<<d[ex][ey]<<endl;
		
	return 0;
} 
