#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
int const SIZE=1000001;
int isprime[SIZE+5];
int c[SIZE+5];
vector<int> semi_prime;

void special_sieve(){
	for(int i=5;i*i<=SIZE;i+=4){
		if(!isprime[i]){
			for(int j=i;i*j<=SIZE;j+=4){
				isprime[i*j]=isprime[i]+isprime[j]+1;
			}
		}
	}
}

int main(){
	special_sieve();
	for(int i=1;i<=SIZE;i++){
		if(isprime[i]==1)
			c[i]=c[i-1]+1;
		else
			c[i]=c[i-1];
	}

	int num;
	while(cin>>num){
		if(num==0)
			break;
		cout<<num<<" "<<c[num]<<endl;
	}
	
	return 0;
}
