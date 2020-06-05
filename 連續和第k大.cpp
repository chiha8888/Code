#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int A[20005];
int S[20005];
int s[20005];	//C排序時用 
int Count;
int n,k;

void merge(int l,int m,int r){
	int n1=m-l+1; //個數  
	int n2=r-m;	//個數 
	int L[n1+2];
	int R[n2+2];
	for(int i=1;i<=n1;i++){
		L[i]=s[l+i-1];
	}
	for(int i=1;i<=n2;i++){
		R[i]=s[m+i];
	}
	L[n1+1]=INF;
	R[n2+1]=INF;
	int i=1,j=1;
	for(int k=l;k<=r;k++){
		if(L[i]<=R[j])
			s[k]=L[i++];
		else
			s[k]=R[j++];
	}
	
} 
void merge_sort(int l,int r,int x){
	if(l<r){
		int mid=(l+r)/2;
		merge_sort(l,mid,x);	//[l,mid]
		merge_sort(mid+1,r,x);	//[mid+1,r]
		
		//爬蟲法計算區間個數 
		int p=mid+1;
		for(int i=l;i<=mid;i++){
			while(p<=r&&s[p]-s[i]<=x)
				p++;
			Count+=r-p+1;
		} 
		merge(l,mid,r);
	}
}

bool C(int x){	//連續和比X大的個數是否 > k-1 
	Count=0;
	memcpy(s,S,sizeof(S));
	merge_sort(0,n,x);	//得知count 
	return Count>k-1;
}

int main(){

	while(cin>>n>>k){
		if(n==0&&k==0)
			break;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>A[i];
			S[i]=S[i-1]+A[i];
		}
		int lb=n*(-10000)-1;
		int ub=n*10000;
		while(ub-lb>1){	// (  ]		//....111111110000000..... 找最左邊的0 
			int mid=(lb+ub)/2;
			if(C(mid))
				lb=mid;
			else
				ub=mid;	
		}
		cout<<ub<<endl;
	}
	
	return 0;
} 
