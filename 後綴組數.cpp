#include<bits/stdc++.h>
using namespace std;
int d[5005];
char s[5005];

bool suffix_cmp(int off1,int off2){
	return strcmp(s+off1,s+off2)<0;
}

int main(){
	cin>>s;
	for(int i=0;i<strlen(s);i++)
		d[i]=i;
	sort(d,d+strlen(s),suffix_cmp);
	for(int i=0;i<strlen(s);i++){
		for(int j=d[i];j<strlen(s);j++)
			cout<<s[j];
		cout<<endl;
	}
} 
