#include<bits/stdc++.h>
using namespace std;

long long lcm(long long a,long long b){	//最大公倍數 
	long long gc=__gcd(a,b);
	return a*b/gc;	
}
/*
3
2 5 
3 7 
6 9 
*/ 
int main(){
	int n;
	cin>>n;
	long long now_r=0,now_q=1;
	long long q,r;
	bool found=false;
	for(int i=0;i<n;i++){
		cin>>r>>q;
		found=false;
		for(int j=0;j<q;j++){
			if((now_r+now_q*j)%q==r){
				now_r+=now_q*j;
				now_q=lcm(now_q,q);
				found=1;
				break;
			}
		}
		if(!found){
			cout<<"not found"<<endl;
			return 0;
		}
	}
	cout<<now_r<<endl;
	return 0; 
} 
