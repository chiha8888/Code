#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
int n,k;
int a[1000005];
deque<int> dq;

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//算min	維持遞增 
	for(int i=1;i<=n;i++){
		if(dq.empty()||a[dq.back()]<=a[i])
			dq.push_back(i);
		else{
			while(!dq.empty()&&a[dq.back()]>a[i])
				dq.pop_back();
			dq.push_back(i);
		}
		if(i>=k){
			while(abs(dq.front()-i)+1>k)
				dq.pop_front();
			printf("%d ",a[dq.front()]);
		}
	}
	cout<<endl;
	dq.clear();
	//算max 維持遞減
	for(int i=1;i<=n;i++){
		//push
		if(dq.empty()||a[dq.back()]>=a[i])
			dq.push_back(i);
		else{
			while(!dq.empty()&&a[dq.back()]<a[i])
				dq.pop_back();
			dq.push_back(i);
		}
		//取窗口 
		if(i>=k){
				while(abs(dq.front()-i)+1>k)
					dq.pop_front();
				printf("%d ",a[dq.front()]);
			}
	}	
	cout<<endl;
	return 0;
} 
