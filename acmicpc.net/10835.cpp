#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int find_max_score(int i, int j, const vector<int>& dummy1, const vector<int>& dummy2, vector<vector<int>>& DP) {

	if (DP[i][j] != -1) return DP[i][j];

	int& ret = DP[i][j];

	if (i == 0 || j == 0) return 0;
		

	if (dummy1[i] <= dummy2[j]) {
		return ret = max(find_max_score(i - 1, j, dummy1, dummy2, DP), find_max_score(i - 1, j - 1, dummy1, dummy2, DP));
	}
	else {
		return ret= max(max(find_max_score(i - 1, j, dummy1, dummy2, DP), find_max_score(i - 1, j - 1, dummy1, dummy2, DP)), find_max_score(i,j-1,dummy1,dummy2,DP)+dummy2[j] );
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> dummy1(N + 1, 0);
	vector<int> dummy2(N + 1, 0);
	vector<vector<int>> DP(N + 1, vector<int>(N + 1, -1));

	for (int i = N; i >= 1; i--) {
		int tmp;
		cin >> tmp;
		dummy1[i] = tmp;
	}
	for (int i = N; i >= 1; i--) {
		int tmp;
		cin >> tmp;
		dummy2[i] = tmp;
	}


	cout << find_max_score(N, N, dummy1, dummy2, DP);

	return 0;
}