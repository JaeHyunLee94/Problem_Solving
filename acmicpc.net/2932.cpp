#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	vector<vector<int>> dp(501, vector<int>(501, 0));
	vector<vector<int>> triangle(501, vector<int>(501, 0));

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int tmp;
			cin >> tmp;
			triangle[i][j] = tmp;

		}
	}
	dp[1][1] = triangle[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if(j==n) dp[i][j] = dp[i - 1][j-1] + triangle[i][j];
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}
	int ans = dp[n][1];
	for (int i = 1;i<= n; i++) {
		if (dp[n][i] >= ans) ans = dp[n][i];
	}

	cout << ans;



	return 0;
}