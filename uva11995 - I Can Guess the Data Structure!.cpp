#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> input;
vector<int> output;
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	int t,x;
	while(cin>>n){
		input.clear();
		output.clear();
		vector<string> ans;
		for(int i=0;i<n;i++){
			cin>>t>>x;
			if(t==1){
				input.push_back(x);
			}
				
			else
				output.push_back(x);		
		}
		if(output.size()>input.size()){
			cout<<"impossible"<<endl;
			continue;
		}
		int inputl=input.size();
		int outputl=output.size();
		//FIFO
		int i;
		for(i=0;i<outputl;i++){
			if(input[i]!=output[i]){
				break;
			}
		}
		if(i==outputl)
			ans.push_back("queue");
		
		//LIFO
		for(i=0;i<outputl;i++){
			if(input[inputl-1-i]!=output[i]){
				break;
			}
		}
		if(i==outputl)
			ans.push_back("stack");
		
		//priority_queue
		sort(input.begin(),input.end(),cmp);
		for(i=0;i<outputl;i++){
			if(input[i]!=output[i]){
				break;
			}
		}
		if(i==outputl)
			ans.push_back("priority queue");
			
		if(ans.empty())
			cout<<"impossible"<<endl;
		else if(ans.size()==1)
			cout<<ans[0]<<endl;
		else
			cout<<"not sure"<<endl;
	}	
	return 0;
} 
