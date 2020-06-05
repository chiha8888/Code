#include<bits/stdc++.h>
using namespace std;
char t[11+1]="mississippi";
char* s[11];

bool cmp(char* i,char* j){
	return strcmp(i,j)<0;	
}

int main(){
	for(int i=0;i<11;i++)
		s[i]=t+i;

	sort(s,s+11,cmp);
	for(int i=0;i<11;i++){
		cout<<s[i]<<endl;
	}
		
	return 0;	
} 
