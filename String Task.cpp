#include<bits/stdc++.h>
using namespace std;
char vowels[6]={'a','o','y','e','u','i'};
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		s[i]=tolower(s[i]);
	}
	for(int i=0;i<s.length();i++){
		for(int j=0;j<6;j++){
			if(s[i]==vowels[j]){
				s[i]=' ';
				break;	
			}
		}
	}
	for(int i=0;i<s.length();i++){
		if(s[i]!=' '){
			putchar('.');
			putchar(s[i]);
		}
	}
	cout<<endl;
	return 0;
} 
