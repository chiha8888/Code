#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<sstream>
#include<deque>
using namespace std;
deque<int>::iterator iter;
int main(){
	int T,num;
	string s;
	cin>>T;
	while(T--){
		deque<int> dq;
		cin>>s;
		stringstream ss(s);
		while(ss>>s){
			dq.push_back(atoi(s));
		}
		cout<<dq.size()<<endl;
		for(iter=dq.begin();iter!=dq.end();iter++)
			cout<<*iter<<endl; 
	}
	return 0;
} 
