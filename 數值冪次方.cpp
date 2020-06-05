#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long ll;

bool is_prime(ll x){
	for(ll i=2;i*i<=x;i++){
		if(x%i==0)
			return false;
	}
	return true;
}

ll pow_mod(ll a,ll n,ll m){
	if(n==0)
		return 1LL;
	ll re=pow_mod(a*a%m,n/2,m);
	if(n&1)
		re=re*a%m;
	return re%m;
}

int main(){
	ll n;
	while(cin>>n&&n!=0){
		if(is_prime(n)){
			cout<<n<<" is normal."<<endl;
			continue;
		}
		ll a;
		for(a=2;a<n;a++){
			if(pow_mod(a,n,n)!=a){
				cout<<n<<" is normal."<<endl;
				break;
			}	
		}
		if(a==n)
			cout<<"The number "<<n<<" is a Carmichael number."<<endl;
	}
	return 0;
} 
