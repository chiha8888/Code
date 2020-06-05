#include<bits/stdc++.h>
using namespace std;

long long f(long long x){	//O(n^1/2)
	long long i=1,sum=0;
	while(i<=x){
		long long v=x/i;
		long long ito=x/v;
		sum+=(ito-i+1)*v;	//i~itoªº­È³£¬Ov 
		i=ito+1;
	}
	return sum;	
}

int main(){
	long long a,b;
	cin>>a>>b;
	cout<<f(b)-f(a-1)<<endl;
	return 0;
} 
