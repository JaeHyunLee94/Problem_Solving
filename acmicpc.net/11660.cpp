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

	

	int N, M;
	cin >> N >> M;
	vector<vector<int>> mat(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> ans(N + 1, vector<int>(N + 1, 0));



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			mat[i][j] = tmp;
			
		}
	}
	ans[1][1] = mat[1][1];
	for (int i = 2; i <= N; i++) {
		ans[1][i] = ans[1][i - 1] + mat[1][i];
	}
	for (int i = 2; i <= N; i++) {
		ans[i][1] = ans[i-1][1] + mat[i][1];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			ans[i][j] = ans[i][j - 1] + ans[i - 1][j] - ans[i - 1][j - 1] + mat[i][j];

		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << ans[x2][y2] - ans[x2][y1-1] - ans[x1-1][y2] + ans[x1-1][y1-1] << '\n';
	}



	return 0;
}