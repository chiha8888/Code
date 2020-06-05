#include<bits/stdc++.h>
using namespace std;
char _map[105][105];	
int ans;
int di[8] = { -1,-1,0,1,1,1,0,-1 };
int dj[8] = { 0,1,1,1,0,-1,-1,-1 };
int n, m;

void dfs(int i, int j) {
	_map[i][j] = '*';
	for (int k = 0; k<8; k++) {
		int ii = i + di[k];
		int jj = j + dj[k];
		if (ii >= 0 && ii<n&&jj >= 0 && jj<m&&_map[ii][jj]=='@')
			dfs(ii, jj);
	}
}

int main() {

	while (cin >> n >> m) {
		if (n == 0)
			return 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++)
				cin >> _map[i][j];
		}
		ans = 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (_map[i][j] == '@') {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
