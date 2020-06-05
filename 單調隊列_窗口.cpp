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
	//��min	�������W 
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
	//��max ��������
	for(int i=1;i<=n;i++){
		//push
		if(dq.empty()||a[dq.back()]>=a[i])
			dq.push_back(i);
		else{
			while(!dq.empty()&&a[dq.back()]<a[i])
				dq.pop_back();
			dq.push_back(i);
		}
		//�����f 
		if(i>=k){
				while(abs(dq.front()-i)+1>k)
					dq.pop_front();
				printf("%d ",a[dq.front()]);
			}
	}	
	cout<<endl;
	return 0;
} 
