#include<bits/stdc++.h>
using namespace std;
vector<int> vec[7];	

int main(){
	int n;
	cin>>n;
	int bit=0;
	int m=-1;
	while(n>0){
		int num=n%10;
		m=max(m,num);
		for(int i=0;i<num;i++){
			vec[bit].push_back(1);
		}
		for(int i=0;i<9;i++){
			vec[bit].push_back(0);
		}
		bit++;
		n/=10;
	}
	bit-=1;
	
	cout<<m<<endl;
	for(int i=0;i<m;i++){
		int flag=false;
		for(int j=bit;j>=0;j--){
			if(vec[j][i]==1||flag){
				flag=true;
				cout<<vec[j][i];
			}	
		}
		if(i!=m-1)
			cout<<" ";
	} 
	cout<<endl;
	return 0;
} 
