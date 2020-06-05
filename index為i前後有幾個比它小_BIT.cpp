#include<bits/stdc++.h>
using namespace std;

struct Binary_index_tree{
	int s[100005];	//array
	int n;	//size

	Binary_index_tree(int num){
		n=num;
		memset(s,0,sizeof(int)*(num+1));
	}
	void update(int i,int delta){	//+delta
		while(i<=n){
			s[i]+=delta;
			i+=lowbit(i);
		}
	}
	int query(int i){
		int tot=0;
		while(i>0){
			tot+=s[i];
			i-=lowbit(i);
		}
		return tot;
	}
	int lowbit(int a){
		return a&(-a);
	}
}; 

int a[100005];
set<int> b;
set<int>::iterator it;
map<int,int> _map;
vector<int> ans;

int main(){
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		a[i]=num;
		b.insert(num);
	}
	reverse(a,a+n);
	
	int rank=1;	
	for(it=b.begin();it!=b.end();it++){
		_map.insert(make_pair(*it,rank));
		//cout<<"insert "<<*it<<" => "<<rank<<endl;
		rank++;
	}
	Binary_index_tree bit(n);
	for(int i=0;i<n;i++){
		int rank=_map[a[i]];
		int tot=bit.query(rank-1);
		ans.push_back(tot);
		bit.update(rank,1);
		/*for(int i=0;i<=n;i++){
            cout<<bit.s[i]<<" ";
        }
        cout<<endl;*/
	}
	reverse(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
