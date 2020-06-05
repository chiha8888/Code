#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int s[300005];
deque<int> dq;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf(" %d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	dq.push_back(0);
	int ans=0;
	for(int i=1;i<=n;i++){
		//¥ýºâ
		while(dq.front()<i-m)
			 dq.pop_front();
		ans=max(ans,s[i]-s[dq.front()]);
		
		//¦A´¡¤J
		if(dq.empty()){
			dq.push_back(i);
		} 
		else{
			while(!dq.empty()&&s[dq.back()]>s[i])
				dq.pop_back();
			dq.push_back(i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
