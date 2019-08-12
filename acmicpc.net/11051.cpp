#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;




int main() {

	int N, K;
	cin >> N >> K;
	vector<vector<int>> dp(N+1, vector<int>(N + 1, 0));
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (i == j || j==0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] % 10007 + dp[i - 1][j] % 10007) % 10007;
		}
	}
	cout << dp[N][K] << '\n';

	return 0;
}