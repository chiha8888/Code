#include<bits/stdc++.h>
using namespace std;
int n,k;
int A[150005];
int ans;
int index;

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int tmp=0;
	for(int i=0;i<k;i++){
		tmp+=A[i];
	}
	ans=tmp;
	index=1;
	for(int i=1;i+k-1<n;i++){
		tmp=tmp-A[i-1]+A[i+k-1];
		if(tmp<=ans){
			ans=tmp;
			index=i+1;
		}
	}		
	
	cout<<index<<endl;
	
	
	
} 
