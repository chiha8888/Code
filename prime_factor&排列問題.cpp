#include<iostream>
#include<cstdlib>
#include<map>
using namespace std;
typedef long long ll;
map<int,int>::iterator it;

ll level(ll n){
	if(n==1||n==0)
		return 1;
	return n*level(n-1);
}

map<int,int> prime_factor(int n){
	map<int,int> factor;
	for(int i=2;i*i<=n;i++){
		while(n%i==0){
			factor[i]++;
			n/=i;
		}
	}
	if(n!=1)
		factor[n]++;
	return factor;
}

int main(){
	int num;
	while(cin>>num){
		ll ans1=0,ans2; 
		map<int,int> factor=prime_factor(num);
		for(it=factor.begin();it!=factor.end();it++){
			ans1+=it->second;
		}
		ans2=level(ans1);
		for(it=factor.begin();it!=factor.end();it++){
			ans2/=level(it->second);
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
