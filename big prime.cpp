#include<bits/stdc++.h>
#define SIZE 1000005
using namespace std;
bool is_prime_small[SIZE];
bool is_prime[SIZE];
int main(){
	int a,b;
	cin>>a>>b;
	for(int i=2;i*i<=b;i++)
		is_prime_small[i]=true;
	for(int i=0;i<b-a;i++)
		is_prime[i]=true;
	
} 
