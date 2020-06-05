#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
const double EPS=1E-8;
typedef vector<double> vec;
typedef vector<vec> matrix;
char _map[15][15];
bool can_goal[15][15];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int N,M; 
/*
10 10
..######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
#.######.#
....#.....
.####.####
....#.....
*/
/*
3 10
.#...#...#
.#.#.#.#.#
...#...#..
*/
/*
10 10
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
*/
vec gauss_jordan(const matrix &A,const vec &b){
	int n=A.size();
	matrix B(n,vec(n+1));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			B[i][j]=A[i][j];
		}
	}
	for(int i=0;i<n;i++){
		B[i][n]=b[i];
	}
	
	for(int i=0;i<n;i++){
		//find big
		int pivot=i;
		for(int j=i+1;j<n;j++){
			if(abs(B[pivot][i])<abs(B[j][i]))
				pivot=j;
		}
		swap(B[i],B[pivot]);
		//no solution & multi solution
		if(abs(B[i][i])<EPS)
			return vec();
			
		for(int j=i+1;j<=n;j++)
			B[i][j]/=B[i][i];	
		for(int j=0;j<n;j++){
			if(j!=i){
				for(int k=i+1;k<=n;k++){
					B[j][k]-=B[i][k]*B[j][i];
				}
			}	
		}
	}
	vec x(n);
	for(int i=0;i<n;i++)
		x[i]=B[i][n];
	return x;
}

void dfs(int x,int y){
	can_goal[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&nx<N&&ny>=0&&ny<M&&_map[nx][ny]!='#'&&can_goal[nx][ny]!=true)
			dfs(nx,ny);
	}	
	return;
}

double solve(){
	matrix A(N*M,vec(N*M,0));
	vec b(N*M,0);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			can_goal[i][j]=false;
	dfs(0,0);
			
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			if((x==N-1&&y==M-1)||!can_goal[x][y]){
				A[x*M+y][x*M+y]=1;
				continue;
			}
			
			double move=0;
			for(int k=0;k<4;k++){
				int nx=x+dx[k],ny=y+dy[k];
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&can_goal[nx][ny]){
					A[x*M+y][nx*M+ny]=-1;
					move++;
				}
			}
			A[x*M+y][x*M+y]=move;
			b[x*M+y]=move;
		}
	}
	
	vec x=gauss_jordan(A,b);
	return x[0];
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>_map[i][j];
	double ans=solve();
	printf("%.8lf\n",ans);
	return 0;
} 
