#include<cstdlib>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
const double EPS=1E-8;
typedef vector<double> vec;
typedef vector<vec> matrix;
/*
3
1 -2 3
4 -5 6
7 -8 10
6 12 21
*/
vec gauss_jordan(const matrix &A,const vec &b){
	int n=A.size();
	matrix B(n,vec(n+1));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			B[i][j]=A[i][j];
		}
	}
	for(int i=0;i<n;i++){
		B[i][n]=b[i];
	}
	
	for(int i=0;i<n;i++){
		//find big
		int pivot=i;
		for(int j=i+1;j<n;j++){
			if(abs(B[pivot][i])<abs(B[j][i]))
				pivot=j;
		}
		swap(B[i],B[pivot]);
		//no solution & multi solution
		if(abs(B[i][i])<EPS)
			return vec();
			
		for(int j=i+1;j<=n;j++)
			B[i][j]/=B[i][i];	
		for(int j=0;j<n;j++){
			if(j!=i){
				for(int k=i+1;k<=n;k++){
					B[j][k]-=B[i][k]*B[j][i];
				}
			}	
		}
	}
	vec x(n);
	for(int i=0;i<n;i++)
		x[i]=B[i][n];
	return x;
}

int main(){
	int m;
	cin>>m;
	matrix A(m,vec(m));
	vec b(m);
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>A[i][j];
		}
	}
	for(int i=0;i<m;i++)
		cin>>b[i];
	vec x=gauss_jordan(A,b);
	for(int i=0;i<m;i++){
		cout<<x[i]<<endl;
	}
	return 0;	
} 
