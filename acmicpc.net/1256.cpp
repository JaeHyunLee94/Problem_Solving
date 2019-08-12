#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	long long N, M, K;
	
	cin >> N >> M >> K;
	long long len = N + M;
	vector<vector<long long>> dp(201, vector <long long>(201, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= 200; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= 200; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] > 1000000001 ? 1000000001 : dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	
	

	if (dp[N+M][N] != 1000000001 && dp[N + M][N]<K) cout << -1;
	else {
		for (long long i = 0; i<len; i++) {
			if (N == 0) {
				for (long long j = 0; j < M; j++) cout << 'z';
				break;
			}
			if (M == 0) {
				for (long long j = 0; j < N; j++) cout << 'a';
				break;
			}
			if (K == 1) {
				for (long long j = 0; j < N; j++) cout << 'a';
				for (long long j = 0; j < M; j++) cout << 'z';
				break;
			}

			long long is_big = dp[N + M - 1][N - 1];
			if (is_big == 1000000001 || is_big >= K) {

				cout << 'a';

				N -= 1;
			}


			else {
				K -= is_big;
				cout << 'z';

				M -= 1;
			}
		}
	}



	return 0;
}