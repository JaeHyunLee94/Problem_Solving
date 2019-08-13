#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int>> ret_floyd(const vector<vector<int>>& ans_mat,int V) {
	vector<vector<int>> ans = ans_mat;
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
			}
		}
	}

	return ans;
}

bool is_equal(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j]) return false;
		}
	}
	return true;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V;
	cin >> V;

	vector<vector<int>> min_mat(V, vector<int>(V, 0));
	vector<vector<int>> ans_mat(V, vector<int>(V, 9999999));


	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			int tmp;
			cin >> tmp;
			min_mat[i][j] = tmp;
			if (i == j) ans_mat[i][j] = 0;

		}
	}
	
	bool is_find = true;
	int cncnt = 0;
	while (!is_equal(min_mat, ret_floyd( ans_mat,V))) {
		vector<vector<int>> ff = ret_floyd(ans_mat, V);
		int y=0, x=1;
		int min = 999999;
		for (int i = 0; i < V; i++) {
			for (int j = i+1; j < V; j++) {
				if (min_mat[i][j] != ff[i][j] && min > min_mat[i][j]) {
					y = i;
					x = j;
					min = min_mat[i][j];
				}
			}
		}

		ans_mat[y][x] = min_mat[y][x];
		ans_mat[x][y] = min_mat[y][x];
		cncnt++;
		if (cncnt > V * (V + 1) / 2) {
			is_find = false;
			break;
		}

	}
	if (!is_find) cout << -1 << '\n';
	else {
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < V; i++) {
			for (int j = i + 1; j < V; j++) {
				if (ans_mat[i][j] != 9999999) {
					cnt++;
					sum += ans_mat[i][j];
				}
			}
		}
		cout << sum << '\n';
	}
	

	


	return 0;


}