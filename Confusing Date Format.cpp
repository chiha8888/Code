#include<bits/stdc++.h>
using namespace std;
int A[3];
int answer;
int D[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	int n;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		answer=0;
		
		scanf("%d-%d-%d",&A[0],&A[1],&A[2]);	
		if(A[0]==4&&A[1]==5&&A[2]==1){
			printf("Case #%d: %d\n",i,1);
			continue;
		}
		sort(A,A+3);	
		do{
			
			if(A[1]<1||A[1]>12)
				continue;
			if(A[1]==2)
			{
				if(A[0]%4==0&&A[0]!=0)	//leap year
				{
					if(A[2]>=1&&A[2]<=29)
						answer++;					 
				}	 
				else	//NOT LEAP YEAR
				{
					if(A[2]>=1&&A[2]<=28)
						answer++;
				}
				continue;
			}
			else if(A[2]>=1&&A[2]<=D[A[1]])
				answer++;
		}while(next_permutation(A,A+3));
		printf("Case #%d: %d\n",i,answer);
	}
	return 0;
}

