#include<bits/stdc++.h>
using namespace std;
bool prime[1000005];

int main()
{
	for(int i=0;i<1000005;i++)
		prime[i]=true;
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<1000005;i++){
		if(prime[i])
		{
			for(int j=i*2;j<1000005;j+=i)
				prime[j]=false;
		}
	}
	int n;
	long long num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		if(floor(sqrt(num))*floor(sqrt(num))==num){
			if(prime[(int)sqrt(num)]){
				cout<<"YES"<<endl;
				continue;
			}
			else{
				cout<<"NO"<<endl;
				continue;
			}	
		}
		else
			cout<<"NO"<<endl;	
	}
	
	return 0;
} 
