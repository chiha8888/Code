#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
	cin>>n;
	for(int i=0;i<2*n+3;i++){
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<"#";
		for(int j=0;j<n;j++){
			cout<<".";
		}
		cout<<"#";
		for(int j=0;j<n;j++){
			cout<<".";
		}
		cout<<"#"<<endl;
	}
	//mid
	for(int i=0;i<2*n+3;i++){
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<"#";
		for(int j=0;j<n;j++){
			cout<<".";
		}
		cout<<"#";
		for(int j=0;j<n;j++){
			cout<<".";
		}
		cout<<"#"<<endl;
	}
	for(int i=0;i<2*n+3;i++){
		cout<<"#";
	}
	cout<<endl;	
	return 0;
} 
