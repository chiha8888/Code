#include<bits/stdc++.h>
using namespace std;
int N,n;
string str;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>n;
		n--;
		while(n>=0){
			if((str=to_string(n)).length()%2==0){
				map<int,int> mapp;
				for(int j=0;j<str.length();j++){
					mapp[str[j]]++;
				}
				if()
			}
			else{
				n--;
				n=n>>1;
			}
		}
	}
	
} 
