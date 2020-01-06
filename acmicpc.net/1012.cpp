#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int M, N;

void dfs(const vector<vector<int>>& mat, vector<vector<int>>& is_visit, int y, int x) {

	is_visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < M && yy >= 0 && yy < N && mat[yy][xx] == 1 && !is_visit[yy][xx]) {
			dfs(mat, is_visit, yy, xx);
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
		int K;
		int ans = 0;
		cin >> M >> N >> K;
		vector<vector<int>>mat(N, vector<int>(M, 0));
		vector<vector<int>>is_visit(N, vector<int>(M, 0));
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			mat[y][x] = 1;
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (!is_visit[y][x] && mat[y][x]==1) {
					dfs(mat, is_visit, y, x);
					ans++;
				}
			}
		}
		cout << ans << '\n';

	}



	return 0;
}