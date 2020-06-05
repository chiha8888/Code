#include<bits/stdc++.h>
using namespace std;
int n;
long long h[100005];
/*
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
*/
int main(){
	while(cin>>n){
		if(n==0)
			return 0;
		for(int i=0;i<n;i++)
			cin>>h[i];
		stack<int> s;
		int s_top;	
		int i=0;
		long long ans=-1;
		long long area;
		while(i<n){
			if(s.empty()||h[s.top()]<=h[i])
				s.push(i++);
			else{
				s_top=s.top();	s.pop();
				area=h[s_top]*(s.empty()?i:i-s.top()-1);
				ans=max(ans,area);
			}
		}
		while(!s.empty()){
			s_top=s.top(); s.pop();
			area=h[s_top]*(s.empty()?i:i-s.top()-1);
			ans=max(ans,area);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
