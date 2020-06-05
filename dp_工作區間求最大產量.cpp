#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,M,R;
ll dp[1000005];
//dp[i]=1~i hours maximum productivity
struct task{
	int start;
	int end;
	int efficiency;
}tasks[1005];

bool cmp(const task &a,const task &b){
	return a.end<b.end;
}

int main(){
	cin>>N>>M>>R;
	int a,b,c;
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		tasks[i].start=a; tasks[i].end=b; tasks[i].efficiency=c;
	}
	sort(tasks,tasks+M,cmp);
	int t=0;
	for(int i=1;i<=N;i++){
		ll res=dp[i-1];	//no task end at i'th hour
		while(tasks[t].end==i){	//have task end at i'th hour
			if(tasks[t].start-R>=0)
				res=max(res,tasks[t].efficiency+dp[tasks[t].start-R]);
			else
				res=max(res,(ll)tasks[t].efficiency);
			t++;
		}
		dp[i]=res;
	}
	
	cout<<dp[N]<<endl;
	
	return 0;
} 
