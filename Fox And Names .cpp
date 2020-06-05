#include<bits/stdc++.h>
using namespace std;
string s[105];
bool used[26][26];
vector<int> edge[26];
int indeg[26];

bool compare(string s1,string s2){
	int ll=min(s1.length(),s2.length());
	int i;
	for(i=0;i<ll;i++){
		if(s1[i]!=s2[i]){
			int c1=s1[i]-'a';
			int c2=s2[i]-'a';
			if(!used[c1][c2]){
				edge[c1].push_back(c2);
				indeg[c2]++;
				used[c1][c2]=true;
			}
			break;			
		}	
	}
	//cout<<i<<" "<<ll<<" "<<s1[i]<<s2[i]<<endl;
	if(i==ll&&s1[i-1]==s2[i-1]&&s1.length()>s2.length()){
		cout<<"Impossible"<<endl;
		return true;
	}
	return false;	
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];		
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(compare(s[i],s[j]))
				return 0;	
		}
	}
	queue<int> que;
	vector<char> ans;
	for(int i=0;i<26;i++){
		if(!indeg[i])
			que.push(i);
	}
	for(int i=0;i<26;i++){
		if(que.empty())
			break;
		int k=que.front(); que.pop();
		ans.push_back('a'+k);
		for(int j=0;j<edge[k].size();j++){
			if(--indeg[edge[k][j]]==0)
				que.push(edge[k][j]);
		}
	}
	if(ans.size()==26){
		for(int i=0;i<26;i++){
			cout<<ans[i];
		}
		cout<<endl;
	}
	else{
		cout<<"Impossible"<<endl;
	}
	
	return 0;
} 
