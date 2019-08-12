#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>




using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 2147483647));
	vector<pair<int, int>> mat(n+1);

	for (int i = 1; i <=n; i++) {
		int col, row;
		cin >> row >> col;
		mat[i] = make_pair(row, col);
	}

	for (int i = 1; i < n; i++) {
		dp[i][i + 1] = mat[i].first*mat[i].second*mat[i + 1].second;
		dp[i][i] = 0;
	}


	dp[n ][n ] = 0;
	for (int dif = 2; dif < n; dif++) {
		for (int i = 1; i + dif <= n; i++) {

			for (int k = i ; k < i + dif; k++) {
				dp[i][i + dif] = min(dp[i][i + dif], dp[i][k] + dp[k + 1][i + dif] + mat[i].first*mat[k+1].first*mat[i + dif].second);
			}
		}
	}
	if(n!=1) cout << dp[1][n];
	else cout << mat[1].first*mat[1].second;
	


	return 0;
}