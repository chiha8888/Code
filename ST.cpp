// C++ program to do range minimum query 
// using sparse table 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 500 
 
int lookup[MAX][MAX]; 

// Fills lookup array lookup[][] in bottom up manner. 
void buildSparseTable(int *arr, int n) 
{ 
	for (int i = 0; i < n; i++) 
		lookup[i][0] = arr[i]; 

	// Compute values from smaller to bigger intervals 
	for (int j = 1; (1 << j) <= n; j++) { 
		for (int i = 0; (i + (1 << j) - 1) < n; i++){ 
			lookup[i][j]=min(lookup[i][j-1],lookup[i+(1<<(j-1))][j-1]);
		}
	} 
} 

// Returns minimum of arr[L..R] 
int query(int l, int r) 
{ 
	int h =log2(r-l+1);
	int len = 1<<h;
	return min( lookup[l][h] , lookup[r-len+1][h] );
} 

// Driver program 
int main() 
{ 
	int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 }; 
	int n = sizeof(a) / sizeof(a[0]);
	cout<<n<<endl; 
	buildSparseTable(a, n); 
	cout << query(0, 4) << endl; 
	cout << query(4, 7) << endl; 
	cout << query(7, 8) << endl; 
	return 0; 
} 

