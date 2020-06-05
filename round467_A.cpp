#include<bits/stdc++.h>
using namespace std;
int n;
set<int> s;
int main(){
	cin>>n;
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		if(num!=0)
			s.insert(num);
	}

	cout<<s.size()<<endl;
	return 0;
	
} 
