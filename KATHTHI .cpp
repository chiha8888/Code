#include<bits/stdc++.h>
using namespace std;

char _map[1000][1000];
int n,m;
int d[1000][1000];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

bool isvalid(int _n,int _m){
	if(_n>=0&&_n<n&&_m>=0&&_m<m)
		return true;
	else 
		return false;
}

void bfs(){
	deque<pair<int,int> > que;
	que.push_front(make_pair(0,0));
	d[0][0]=0;
	while(!que.empty()){
		pair<int,int> v=que.front();
		que.pop_front();
		for(int i=0;i<4;i++){
			int tmpn=v.first+dy[i];
			int tmpm=v.second+dx[i];
			if(isvalid(tmpn,tmpm)){
				if(_map[tmpn][tmpm]==_map[v.first][v.second]&&d[tmpn][tmpm]>d[v.first][v.second])//d¤p 
				{
					d[tmpn][tmpm]=d[v.first][v.second];
					que.push_front(make_pair(tmpn,tmpm));
				}
				
				else if(_map[tmpn][tmpm]!=_map[v.first][v.second]&&d[tmpn][tmpm]>d[v.first][v.second]+1)//d¤j 
				{
					d[tmpn][tmpm]=d[v.first][v.second]+1;
					que.push_back(make_pair(tmpn,tmpm));
				}
			}
		}
	}
}

int main(){
	int T,t;
	cin>>T;
	for(int t=0;t<T;t++){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf(" %c",&_map[i][j]);
			}
		}

		memset(d,0x70,sizeof(d));
		bfs();
		cout<<d[n-1][m-1]<<endl;
	}
	return 0;
}
