#include<iostream>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int SIZE=10000;
bool isprime[SIZE];

void sieve(){	//O(n)
	for(int i=0;i<SIZE;i++)
		isprime[i]=true;
	isprime[0]=isprime[1]=false;
		
	for(int i=2;i<SIZE;i++){
		if(isprime[i]){
			for(int j=i*2;j<SIZE;j+=i){
				isprime[j]=false;
			}
		}	
	}
}

vector<int> kinds(int a){	//8+9+9+9 kinds of transform
	vector<int> re;
	for(int i=0;i<4;i++){
		int mul=(int)pow(10.0,i);
		int c=(a/mul)%10;
		int temp=a-c*mul;
		for(int j=0;j<=9;j++){
			if(j==c||(i==3&&j==0))	//no '0XXX'
				continue;
			if(isprime[temp+j*mul]){
				re.push_back(temp+j*mul);
				/*cout<<"c:"<<c<<" mul:"<<mul<<" temp:"<<temp<<endl;
				cout<<"push_back: "<<temp+j*mul<<endl;*/
			}
				
		}
	}
	return re;
}

int const INF=100000000;
int d[SIZE];
int bfs(int s,int t){
	for(int i=0;i<SIZE;i++)
		d[i]=INF;
	d[s]=0;
	
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int now=que.front(); que.pop();
		if(now==t)
			return d[t];
			
		vector<int> trans=kinds(now);
		for(int i=0;i<trans.size();i++){
			int to=trans[i];
			if(d[to]==INF){	//haven't walk before
				que.push(to);
				d[to]=d[now]+1;
			}
		}
	}
	
	return -1;	//fail to reach t
}

int main(){
	sieve();
	int T,s,t,ans;
	cin>>T;
	while(T--){
		cin>>s>>t;
		ans=bfs(s,t);
		if(ans==-1)
			cout<<"Impossible"<<endl;
		else 
			cout<<ans<<endl;
	}
	return 0;
}
