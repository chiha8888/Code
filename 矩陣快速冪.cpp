#include<iostream>
#include<vector>

using namespace std;
typedef vector<vector<long long> > mat;
long long k;
long long o[105];

mat multi(mat &a,mat &b){
	mat re(k,vector<long long>(k));
	for(int i=0;i<k;i++){
		for(int p=0;p<k;p++){
			for(int j=0;j<k;j++){
				re[i][j]=(re[i][j]+a[i][p]*b[p][j])%10000;
			}
		}
	}
	return re;
}

mat matrix_pow(mat A,long long n){
	mat ans(k,vector<long long>(k));
	for(int i=0;i<k;i++){
		ans[i][i]=1;
	}
	while(n){
		if(n&1){
			ans=multi(ans,A);
		}
		A=multi(A,A);
		n/=2;
	}
	return ans;
}


int main(){
	while(cin>>k){
		if(k==0)
			return 0;
			
		mat a(k,vector<long long>(k));
		for(int i=k-1;i>=0;i--)
			cin>>o[i];
		for(int i=0;i<k;i++)
			cin>>a[0][i];
		for(int i=1;i<k;i++){
			a[i][i-1]=1;
		}
		int c;
		cin>>c;
	
	
		if(c<k){
			cout<<o[k-1-c]<<endl;
			continue;
		}
			
		long long ans=0;
		a=matrix_pow(a,c-k+1);
		for(int i=0;i<k;i++){
			ans+=a[0][i]*o[i];
		}
		
		cout<<ans<<endl;
	}
	
	
	return 0;
} 
