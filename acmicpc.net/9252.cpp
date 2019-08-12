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

	string str1, str2;
	cin >> str1 >> str2;
	string result;
	
	vector<vector<int>> dp(1001, vector<int>(1001,0));
	
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {

			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}

		}
	}
	cout << dp[str1.size()][str2.size()] << '\n';

	int inx1 = str1.size();
	int inx2 = str2.size();

	while (inx1 >= 1 && inx2 >= 1) {
		if (dp[inx1 - 1][inx2] == dp[inx1][inx2]) {
			inx1--;
			continue;
		}
		else if (dp[inx1][inx2 - 1] == dp[inx1][inx2]) {
			inx2--;
			continue;
		}
		else {
			result = str1[inx1 - 1] + result;
			inx1--;
			inx2--;
		}


	}
	cout << result;


	return 0;
}