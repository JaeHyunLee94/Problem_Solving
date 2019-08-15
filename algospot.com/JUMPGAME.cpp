#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N;

void find_w(const vector<vector<int>>& table, vector<vector<int>>& DP) {

	queue <pair<int, int>> q;
	q.push(make_pair(0, 0));

	while(!q.empty()) {

		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if (DP[i][j] == 1) continue;
		DP[i][j] = 1;
		if (i  < N && j + table[i][j] < N) {
			q.push(make_pair(i , j + table[i][j]));
		}
		if (i + table[i][j] < N && j  < N) {
			q.push(make_pair(i + table[i][j], j));
		}



	}


}




int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		cin >> N;

		vector<vector<int>> table(N, vector<int>(N, 0));
		vector<vector<int>> DP(N, vector<int>(N, 0));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int tmp;
				cin >> tmp;
				table[i][j] = tmp;
			}
		}
		find_w(table, DP);
		cout << (DP[N - 1][N - 1]  ? "YES" : "NO" )<< '\n';


	}
	
	






	return 0;
}