#include<bits/stdc++.h>
using namespace std;
int n;


bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	int t,x;
	while(cin>>n){
		stack<int> s;
		deque<int> d;
		priority_queue<int> pq;
		bool iss=true,isd=true,isdq=true;
		for(int i=0;i<n;i++){
			cin>>t>>x;
			if(t==1){
				s.push(x);
				q.push(x);
				pq.push(x);
			}
			else{
				//is stack?
				if(s.top()==x)
					s.pop();
				else
					iss=false;
				//is queue?
				if(q.front()==x)
					q.pop();
				else
					isq=false;
				//is pq?
				if(pq.top()==x)
					pq.pop();
				else
					ispq=false;
			}
		}
		if(iss||isq||ispq){
			if(iss&&!isq&&!ispq)
				cout<<"stack"<<endl;
			else if(!iss&&isq&&!ispq)
				cout<<"queue"<<endl;
			else if(!iss&&!isq&&ispq)
				cout<<"priority queue"<<endl;
			else
				cout<<"not sure"<<endl;
		}
		else{
			cout<<"impossible"<<endl;
		}
		
	}	
	return 0;
} 
