#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<string>
#include<cmath> 
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);	
}

int main(){
	string s,subs;
	int len;
	ll n;
	while(cin>>s){
		if(s=="0")
			return 0;
		subs=s.substr(2,s.length()-5);
		len=subs.length();
		n=atoi(subs.c_str());
		ll minia,minib=1E18;
		for(int i=1;i<=len;i++){	//repeat digits
			ll a,b;
			a=n-n/(ll)pow(10.0,i);
			b=((ll)pow(10.0,i)-1)*((ll)pow(10.0,len-i));
			//cout<<a<<" "<<b<<endl;
			ll g=gcd(a,b);
			if(b/g<minib){
				minia=a/g;
				minib=b/g;
			}
		}
		cout<<minia<<"/"<<minib<<endl;
	}
	return 0;
}
