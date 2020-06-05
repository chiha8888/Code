#include<bits/stdc++.h>
using namespace std;
deque<int> d;
int c;

int main(){
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	for(int i=0;i<d.size();i++){
		cout<<d[i]<<endl;
		c++;
	}
	d.clear();
	cout<<"count: "<<c<<endl;
	return 0;
} 
