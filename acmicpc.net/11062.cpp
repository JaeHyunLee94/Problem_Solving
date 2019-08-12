#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
vector<vector<vector<int>>> DP(2, vector<vector<int>>(1001, vector<int>(1001, -1)));

int maximun_score(vector<int>& table, vector<int>& sum_until, int i, int j, int k) {

	if (DP[k][i][j] != -1) return DP[k][i][j];


	if (k == 1) DP[k][i][j] = (i == 0 ? sum_until[j] - maximun_score(table, sum_until, i, j, 0) : sum_until[j] - sum_until[i - 1] - maximun_score(table, sum_until, i, j, 0));
	else DP[k][i][j] = max(table[i] + maximun_score(table, sum_until, i + 1, j, 1), table[j] + maximun_score(table, sum_until, i, j - 1, 1));

	return DP[k][i][j];
}



int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int N;
		cin >> N;
		vector<int> table(N);
		vector<int> sum_until(N);
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			table[i] = tmp;
			if (i == 0) sum_until[i] = tmp;
			else sum_until[i] = tmp + sum_until[i - 1];
		}
		
		for (int i = 0; i < N - 1; i++) {
			DP[0][i][i] = table[i];
			DP[1][i][i] = 0;
			DP[0][i][i+1] = max(table[i], table[i + 1]);
			DP[1][i][i+1] = min(table[i], table[i + 1]);
		}
		DP[0][N - 1][N-1] = table[N - 1];
		DP[0][N - 1][N-1] = 0;

		cout << maximun_score(table, sum_until, 0, N - 1, 0) << '\n';


	}



	return 0;
}

