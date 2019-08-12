#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int ans = 0;
	cin >> n >> m;
	
	vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> rec(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= m; j++) {
		
			rec[i][j]=matrix[i][j] = tmp[j-1] - '0';
		}
	}
	


	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			int a, b;
			a = rec[i][j - 1];
			b = rec[i - 1][j];
			int l = min(a, b);
			if (matrix[i][j]==1&& matrix[i][j-1]==1 && matrix[i-1][j]==1 ) {
				if(a==b) rec[i][j] = matrix[i - l][j - l] == 1 ? l + 1 : l;
				else rec[i][j] = l+1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (rec[i][j] >= ans) ans = rec[i][j];

		}
	}
	cout << ans*ans;



	return 0;
}
