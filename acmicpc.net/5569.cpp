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


	int w,h;
	cin >> w >> h;
	vector<vector<vector<int>>> dp(h+1, vector<vector<int>>(w + 1, vector<int>(4, 0)));
	for (int i = 2; i <= w; i++) {
		dp[1][i][0] = 1;

	}
	for (int i = 2; i <= h; i++) {
		dp[i][1][3] = 1;

	}
	
	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			dp[i][j][0] = (dp[i][j - 1][0]% 100000 + dp[i][j - 1][1]% 100000)%100000;
			dp[i][j][1] = dp[i][j - 1][3]%100000;
			dp[i][j][2] = dp[i-1][j][0] % 100000;
			dp[i][j][3] = (dp[i-1][j][2] % 100000 + dp[i-1][j][3] % 100000) % 100000;
		}
	}
	cout << (dp[h][w][0] + dp[h][w][1] + dp[h][w][2] + dp[h][w][3]) % 100000;



	return 0;
}