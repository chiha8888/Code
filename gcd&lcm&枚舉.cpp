#include<iostream>
#include<cstdlib>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
map<ll,ll>::iterator it;
ll d[20];

map<ll,ll> prime_factor(ll a){
	map<ll,ll> res;
	for(ll i=2LL;i*i<=a;i++){
		if(a==1LL)
			break;
		while(a%i==0){
			res[i]++;
			a/=i;
		}
	}
	if(a!=1)
		res[a]++;
	return res;
} 

int main(){
	ll gcd,lcm;
	while(cin>>gcd>>lcm){
		map<ll,ll> res=prime_factor(lcm/gcd);
		int count=0;
		for(it=res.begin();it!=res.end();it++){
			ll acu=1;
			for(ll i=1;i<=it->second;i++){
				acu*=it->first;
			}
			d[count++]=acu;
		}
		//enum
		ll mini=1E18;
		ll mina,minb;
		for(int i=0;i<(1<<count);i++){
			ll a=gcd,b=gcd;
			for(int j=0;j<count;j++){
				if((i>>j)&1){
					a*=d[j];
				}
				else{
					b*=d[j];
				}
			}
			if((a+b)<mini){
				mini=a+b;
				mina=a;
				minb=b;
			}	
		}
		cout<<min(mina,minb)<<" "<<max(mina,minb)<<endl;
	}
	return 0;
}
