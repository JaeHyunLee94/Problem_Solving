#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
const int INf = 987654321;

int find_ans(int i, int j, vector<vector<int>>& DP) {
	if (DP[i][j] != -1) return DP[i][j];
	int& ret = DP[i][j];

	if (i == 1 || j == 1) {
		if (i == 1 && j == 1) return ret = 0;
		if (j == 1) return ret=i - 1;
		if (i == 1) return ret=j - 1;
	}
	ret = INf;
	for (int k = 1; k <=i/2; k++) {
		ret = min(ret, 1 + find_ans(k, j, DP) + find_ans(i - k, j, DP));
		
	}
	for (int k = 1; k <=j/2; k++) {
		ret = min(ret, 1 + find_ans(i, k, DP) + find_ans(i, j - k, DP));

	}
	return ret;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> DP(n + 1, vector<int>(m + 1, -1));
	cout << find_ans(n,m,DP);





	return 0;
}