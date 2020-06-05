#include<bits/stdc++.h>
using namespace std;

bool check(int n){
	set<int> s;
	for(int i=0;i<4;i++){
		s.insert(n%10);
		n/=10;
	}	
	if(s.size()==4)
		return true;
	else
		return false;
}

int main(){
	int n;
	cin>>n;
	n+=1;
	while(1){
		if(check(n)){
			cout<<n<<endl;
			break;
		}
		n++;
	}
	return 0;
} 
