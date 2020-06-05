#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105][105];
int s[105][105];
int h[105];
/*
6 7
0 1 1 0 1 1 0
0 0 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 0 0 0 1
1 1 0 0 0 1 0
1 1 0 1 1 0 0
0 0

*/
int largest_rectangle(int nown){
	memcpy(h,s[nown],sizeof(int)*m);

	int ans;
	stack<int> s;
	int s_top;
	int area;
	int i=0; 	//右邊pointer 
	while(i<m){
		if(s.empty()||h[s.top()]<=h[i])
			s.push(i++);
		else{
			s_top=s.top();	s.pop();
			area=h[s_top]*(s.empty()?i:i-s.top()-1);
			ans=max(ans,area);
		}
	}
	while(!s.empty()){
		s_top=s.top();	s.pop();
		area=h[s_top]*(s.empty()?i:i-s.top()-1);
		ans=max(ans,area);
	}
	return ans;
}

int main(){
	while(cin>>n>>m){
		if(n==0&&m==0)
			return 0;
		for(int i=0;i<n;i++){	//處理長度 
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				if(i==0){
					s[i][j]=(a[i][j]?0:1);
				}				
				else{
					if(a[i][j])
						s[i][j]=0;
					else
						s[i][j]=s[i-1][j]+1;
				}
			}
		}
		int ans=-1;
		for(int i=0;i<n;i++){	//做N次0 2問題 
			ans=max(ans,largest_rectangle(i));
		} 
		
		cout<<ans<<endl;
	}	
	return 0;
} 
