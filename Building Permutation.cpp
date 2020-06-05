#include<bits/stdc++.h>
using namespace std;
int A[300005];
long long answer;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];		
	}
	sort(A,A+n);
	for(int i=0;i<n;i++)
	{
		answer+=abs(i+1-A[i]);
	}
	cout<<answer<<endl;
	return 0;
} 
