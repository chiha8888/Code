#include<bits/stdc++.h>
// G. Dreamoon and NightMarket
using namespace std;
int a[200005];
int n,k;
int Count;

void dfs(int dim,long long sum,long long x){
	if(Count>k-1||dim==n)
		return;
	if(sum+a[dim]<x){
		Count++;	//����: +1 
		dfs(dim+1,sum,x);
		dfs(dim+1,sum+a[dim],x);
	}
}

bool C(long long x){	//�p��x���ӼƬO�_ > k-1
	Count=0;
	dfs(0,0,x);
	return Count>k-1;	
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);	
	long long lb=1;
	long long ub=1e14+1;
	while(ub-lb>1){
		long long mid=(lb+ub)/2;
		if(!C(mid))
			lb=mid;
		else
			ub=mid;
	}
	cout<<lb<<endl;
	
	return 0;
} 
