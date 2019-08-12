#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int min_click(vector<vector<int>>& DP ,vector<int>& table,int i, int j) {

	int& ret = DP[i][j];
	
	if (ret != 2147483647) return ret;

	if (i == j) return ret = 0;
	if (j == i + 1) return ret = (table[i] != table[j]);
	

	for (int split = i; split < j; split++) {
		ret = min(ret, min_click(DP, table, i, split) + min_click(DP, table, split + 1, j) + (table[i] != table[split + 1]));
	}

	return ret;	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<vector<int>> DP(N, vector<int>(N, 2147483647));
	vector<int> table(N);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		table[i] = tmp;
	}
	

	int ans = min_click(DP, table, 0, N - 1);
	
	cout << ans;




	return 0;
}