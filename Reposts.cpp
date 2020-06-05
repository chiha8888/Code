#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
map<string,int>::iterator iter;
int ans;
/*
5
tourist reposted Polycarp
Petr reposted Tourist
WJMZBMR reposted Petr
sdya reposted wjmzbmr
vepifanov reposted sdya
*/
string trans(string s){
	string re;
	for(int i=0;i<s.length();i++){
		re+=tolower(s[i]);
	}
	return re;
}

int main(){
	int n;
	string s1,ss,s2;
	cin>>n;
	m.insert(make_pair("polycarp",1));
	for(int i=0;i<n;i++){
		cin>>s1>>ss>>s2;
		s1=trans(s1);
		s2=trans(s2);
		iter=m.find(s1);
		if(iter==m.end())
			m[s1]=1;
		iter=m.find(s2);
		if(iter==m.end())
			m[s2]=1;
		m[s1]=max(m[s1],m[s2]+1);
		ans=max(ans,m[s1]);	
	}
	cout<<ans<<endl;
	return 0;
} 
