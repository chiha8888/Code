#include<bits/stdc++.h>
#define SIZE 1000005
using namespace std;
bool is_prime[SIZE];
//O( n*loglog(n) )
int main(){		
	fill(is_prime,is_prime+SIZE,1);
	is_prime[0]=false;
	is_prime[1]=false;
	for(int i=2;i*i<=SIZE;i++){
		if(is_prime[i]){
			for(int j=i*i;j<=SIZE;j+=i){
				is_prime[j]=false;
			}
		}
	}
	int n;
	cin>>n;
	int ans=0;
	for(int i=2;i<=n;i++){	//輸出2~n有幾個質數 
		if(is_prime[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
