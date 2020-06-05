#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int A[1000005];

void merge(int l,int m,int r){
	int n1=m-l+1; //個數  
	int n2=r-m;	//個數 
	int L[n1+2];
	int R[n2+2];
	for(int i=1;i<=n1;i++){
		L[i]=A[l+i-1];
	}
	for(int i=1;i<=n2;i++){
		R[i]=A[m+i];
	}
	L[n1+1]=INF;
	R[n2+1]=INF;
	int i=1,j=1;
	for(int k=l;k<=r;k++){
		if(L[i]<=R[j])
			A[k]=L[i++];
		else
			A[k]=R[j++];
	}
	
} 
void merge_sort(int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		
		merge(l,mid,r);
	}
}

int main(){
	
	for(int i=10;i>=0;i--){
		A[10-i]=i;
	}
	for(int i=0;i<=10;i++)
		cout<<A[i]<<" ";
		cout<<endl<<"-----------"<<endl;
	merge_sort(0,10);
	for(int i=0;i<=10;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}
