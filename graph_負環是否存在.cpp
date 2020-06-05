#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
//POJ 3259
int N,M,W;
int d[505];
struct E{
	int to;
	int cost;
};
vector<E> edge[505];

bool BF(int s){
	memset(d,0x6f,sizeof(d));
	d[s]=0;
	bool change;
	for(int i=1;i<N;i++){
		change=false;
		for(int j=1;j<=N;j++){
			for(int k=0;k<edge[j].size();k++){
				E e=edge[j][k];
				if(d[j]+e.cost<d[e.to]){
					d[e.to]=d[j]+e.cost;
					change=true;
				}
			}
		}
		if(!change)	//if without will be TLE
			break;
	}
	for(int j=1;j<=N;j++){
		for(int k=0;k<edge[j].size();k++){
			E e=edge[j][k];
			if(d[j]+e.cost<d[e.to]){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int T,s,e,t;
	E ee;
	cin>>T;
	while(T--){
		for(int i=0;i<505;i++)
			edge[i].clear();	// eat WA ><
		cin>>N>>M>>W;
		for(int i=0;i<M;i++){
			cin>>s>>e>>t;
			ee.to=e;	ee.cost=t;
			edge[s].push_back(ee);
			ee.to=s;
			edge[e].push_back(ee);
		}
		vector<int> possible;
		for(int i=0;i<W;i++){
			cin>>s>>e>>t;
			ee.to=e; ee.cost=-1*t;	
			edge[s].push_back(ee);
			possible.push_back(e);	
		}
		
		bool exist=false;
		for(int i=0;i<possible.size();i++){
			if(BF(possible[i])){
				exist=true;
				break;
			}		
		}
		if(exist)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl; 
	}
	
	return 0;
} 
