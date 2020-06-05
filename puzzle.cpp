#include<bits/stdc++.h>
using namespace std;
int n,m;
int A[55];
int ans=10e9;

int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>A[i];		
	}
	sort(A,A+m);
	for(int i=0;i+n-1<m;i++){
		ans=min(ans,abs(A[i]-A[i+n-1]));
	}
	cout<<ans<<endl;
	return 0;
} 
