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

	int w, h, n;
	cin >> h >> w >> n;
	vector<vector<int>> mat(h + 1, vector<int>(w + 1, 0));
	vector<vector<vector<int>>> dp(h + 1, vector<vector<int>>(w + 1, vector<int>(2, 0)));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int tmp;
			cin >> tmp;
			mat[i][j] = tmp;
		}
	}
	dp[1][1][1] = (mat[1][1] == 0 ? n / 2 : n - n / 2);
	dp[1][1][0] = n - dp[1][1][1];
	for (int i = 2; i <= w; i++) {
		int tmp_n = dp[1][i - 1][1];
		dp[1][i][1] = (mat[1][i] == 0 ? tmp_n / 2 : tmp_n - tmp_n / 2);
		dp[1][i][0] = tmp_n - dp[1][i][1];
	}
	for (int i = 2; i <= h; i++) {
		int tmp_n = dp[i-1][1][0];
		dp[i][1][1] = (mat[i][1] == 0 ? tmp_n / 2 : tmp_n - tmp_n / 2);
		dp[i][1][0] = tmp_n - dp[i][1][1];
	}

	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			int tmp_n = dp[i - 1][j][0] + dp[i][j - 1][1];
			dp[i][j][1] = (mat[i][j] == 0 ? tmp_n / 2 : tmp_n - tmp_n / 2);
			dp[i][j][0] = tmp_n - dp[i][j][1];


		}
	}
	int starty = 1, startx = 1;
	while (starty!= h+1 && startx != w+1) {
		if (dp[starty][startx][1] > dp[starty][startx][0]) {
			startx++;
		}
		else if(dp[starty][startx][1] < dp[starty][startx][0]){
			starty++;
		}
		else {
			if (mat[starty][startx] == 1) {
				starty++;
			}
			else startx++;
		}
	}


	
	cout << starty << " " << startx;


	return 0;
}