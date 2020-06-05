#include<bits/stdc++.h>
#define SIZE 1000000000
using namespace std;
int p,y;
bool is_prime[SIZE];

int main(){
	//cin>>p>>y;
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
	cout<<"..."<<endl;
	return 0;
} 
