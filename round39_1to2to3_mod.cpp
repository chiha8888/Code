#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long la,lb;

int main(){
	cin>>a>>b;
	
	while(true){
		if(a==0||b==0)
			break;	

		la=a; lb=b;
		if(a>=2*b){
			a=a%(2*b);
		}
		else if(b>=2*a){
			b=b%(2*a);
		}
		else{
			break;
		}
		
		if(la==a&&lb==b)
			break;
	}
	cout<<a<<" "<<b<<endl;
	return 0;	
} 
