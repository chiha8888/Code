#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
//POJ 3669
struct node{	//(x,y) at time t
	int x,y,t;
};
int A[305][305];
bool visit[305][305];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int bfs(){
	queue<node> que;
	node sp;
	sp.x=0;	sp.y=0; sp.t=0;
	que.push(sp);
	if(A[0][0]==0)
		return -1;
	visit[0][0]=true;
	while(!que.empty()){
		node now=que.front(); que.pop();	//now: can reach point
		if(A[now.x][now.y]==0x7f7f7f7f)
			return now.t;
		for(int i=0;i<4;i++){
			int nx=now.x+dx[i],ny=now.y+dy[i];
			if(nx>=0&&ny>=0&&!visit[nx][ny]&&A[nx][ny]>now.t+1){
				node next;
				next.x=nx;	next.y=ny;	next.t=now.t+1;
				que.push(next);
				visit[nx][ny]=true;
			}
		}
	}
	return -1;		
}

int main(){
	int m,x,y,t;
	cin>>m;
	memset(A,0x7f,sizeof(A));
	for(int i=0;i<m;i++){
		cin>>x>>y>>t;
		A[x][y]=min(A[x][y],t);
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&ny>=0)
				A[nx][ny]=min(A[nx][ny],t);
		}
	}
	cout<<bfs()<<endl;
	return 0;
} 
