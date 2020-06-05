#include<bits/stdc++.h>
using namespace std;
int N,Q;
long long data[2*100000+5];	//[l,r)區間和 
long long datb[2*100000+5];	//[l,r)區間都加上的x (lazy tag) 
	
struct Segment_tree{
	
	void update(int l,int r,long long x,int k,int a,int b){	//[l,r)的區間+x 
		if(a>=l&&b<=r)
			datb[k]+=x;
		else if(a<r&&b>l){
			data[k]+=x*(min(r,b)-max(a,l));
			update(l,r,x,k*2+1,a,(a+b)/2);
			update(l,r,x,k*2+2,(a+b)/2,b);
		}
	}
	long long query(int l,int r,int k,int a,int b){
		if(b<=l||a>=r)
			return 0;
		else if(a>=l&&b<=r)
			return data[k]+datb[k]*(a-b);
		else{
			long long sum=datb[k]*(min(r,b)-max(a,l));
			sum+=query(l,r,k*2+1,a,(a+b)/2);
			sum+=query(l,r,k*2+2,(a+b)/2,b);
			return sum;
		}
		
	}
};

int main(){
	Segment_tree st;
	char _char;
	int l,r,add;	//[l,r)
	long long x; 
	cin>>N>>Q;
	for(int i=0;i<N;i++){
		cin>>x;
		st.update(i,i+1,x,0,0,N);
	}
		
	for(int i=0;i<Q;i++){
		cin>>_char;
		if(_char=='Q'){
			cin>>l>>r;
			cout<<st.query(l-1,r,0,0,N)<<endl;
		}
		else{
			cin>>l>>r>>add;
			st.update(l-1,r,add,0,0,N);
		}
			
	}
	return 0;
} 
