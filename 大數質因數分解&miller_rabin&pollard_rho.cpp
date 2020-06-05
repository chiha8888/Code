#include<iostream>
#include<cstdlib>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;
typedef long long ll;
const int TEST=8;

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

ll mul_mod(ll a,ll b,ll m){	//a*b%m
	a%=m;
	b%=m;
	ll re=0;
	ll temp=a;
	while(b){
		if(b&1){
			re+=temp;
			if(re>=m)
				re-=m;
		}
		temp<<=1;
		if(temp>=m)
			temp-=m;
		b>>=1;
	}
	return re%m;
}

ll pow_mod(ll a,ll n,ll m){		//a^n%m
	if(n==0)
		return 1LL;
	ll re=pow_mod(mul_mod(a,a,m),n/2,m);
	if(n&1)
		re=mul_mod(re,a,m);
	return re;
}

bool miller_rabin(ll n){	//is prime?
	if(n<2)
		return false;
	if(n==2)
		return true;
	if((n&1)==0)
		return false;
	ll u=n-1,t=0;	//n-1=2^t*u 
	while((u%2)==0){
		u=u>>1;
		t++;
	}
	
	for(int test=0;test<TEST;test++){	//randomized algo test time 
		ll a=rand()%(n-1)+1;
		ll x=pow_mod(a,u,n);
		ll last=x;	//last x  //secondary judgment
		for(ll i=0;i<t;i++){
			x=mul_mod(x,x,n);
			if(x==1&&last!=1&&last!=n-1)
				return false;	//composite
			last=x;
		}
		if(x!=1)
			return false;	//composite
	}
		
	return true;	//prime (or fake prime)
}

ll pollard_rho(ll n,ll c){	//find a prime factor
	ll x=2,y=2;
	ll i=1,k=2;
	while(1){
		x=(mul_mod(x,x,n)+c)%n;
		ll d=gcd(((x-y)>=0?x-y:-x+y),n);
		if(d>1&&d<n)
			return d;
		if(y==x)
			return n;
		if(++i==k){
			k<<=1;
			y=x;
		}
	}
}

map<ll,ll> factor;
map<ll,ll>::iterator it;
void factorized(ll n){	//factorized
	if(n==1)
		return;
	if(miller_rabin(n)){
		factor[n]++;
		return;
	}
	ll d=n;
	while(d==n){
		d=pollard_rho(n,rand()%(n-1)+1);
	}
		
	factorized(d);
	factorized(n/d);
}

ll d[100];

int main(){
	ll gcd,lcm;
	while(cin>>gcd>>lcm){
		factor.clear();
		memset(d,0,sizeof(d));
		int count=0;
		
		ll n=lcm/gcd;
		while((n&1)==0){			
			factor[2]++; 
			n>>=1;
		}
		factorized(n);
		for(it=factor.begin();it!=factor.end();it++){
			ll acumu=1;
			for(ll i=1;i<=it->second;i++){
				acumu*=it->first;
			}
			d[count++]=acumu;
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
