#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
int dis = 0;
int R = 0;
int C = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


int is_possible(vector<vector<char>>& grid,vector<int>& is_touched ,int y, int x) {

	if (y >= R || y < 0 || x >= C || x < 0) return 0;

	if (is_touched[grid[y][x] - 65]) return 0;

	return 1;

}


void find_ans(vector<vector<char>>& grid, vector<int>& is_touched, int now_y, int now_x) {

	dis++;
	is_touched[grid[now_y][now_x]-65] = 1;
	if (dis > ans) ans = dis;

	for (int i = 0; i < 4; i++) {
		if (is_possible(grid, is_touched, now_y + dy[i], now_x + dx[i])) {
			find_ans(grid, is_touched, now_y + dy[i], now_x + dx[i]);
		}
	}
	is_touched[grid[now_y][now_x] - 65] = 0;
	dis--;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	cin >> R >> C;

	vector<vector<char>> grid(R, vector<char>(C, 65));
	vector<int> is_touched(26, 0);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char tmp;
			cin >> tmp;
			grid[i][j] = tmp;
		}

	}

	find_ans(grid, is_touched, 0, 0);

	cout << ans;


	
}