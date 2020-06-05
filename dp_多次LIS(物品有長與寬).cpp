#include<iostream>
#include<cstdlib>
#include<algorithm> 
using namespace std;
int n;
struct wood{
	int length;
	int weight;
}woods[5005];
bool flag[5005];	//smart way,(better than deque.list's erease)
//int dp[5005];

bool cmp(const wood &a,const wood &b){	//sort cmp
	if(a.length==b.length)
		return a.weight<b.length;
	return a.length<b.length; 
}

int main(){
	int T,l,w;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>l>>w;
			woods[i].length=l; woods[i].weight=w;
			flag[i]=false;
		}
		sort(woods,woods+n,cmp);
		
		int ans=0;
		while(1){
			wood tmp; 
			tmp.length=tmp.weight=0;
			bool change=false;
			for(int i=0;i<n;i++){
				if(flag[i]==false&&woods[i].length>=tmp.length&&woods[i].weight>=tmp.weight){
					flag[i]=true;
					tmp=woods[i];
					change=true;
				}
			}
			if(!change)
				break;
			ans++;
		}
		cout<<ans<<endl;	
	}
	
	return 0;
}
