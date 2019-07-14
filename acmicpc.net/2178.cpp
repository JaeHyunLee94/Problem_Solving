#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct coord {
	int x;
	int y;
};
void bfs(const vector<vector<int>>& maze, vector<vector<int>>& distance, vector<vector<bool>>& is_visit) {

	queue<coord> qq;
	qq.push(coord{ 0,0 });
	is_visit[0][0] = true;
	distance[0][0] = 1;

	int n = maze.size();
	int m = maze[0].size();



	while (!qq.empty()) {
		coord next = qq.front();
		qq.pop();
		int xx=next.x;
		int yy = next.y;

		if (xx - 1 >= 0 && maze[yy][xx - 1] == 1 && !is_visit[yy][xx-1]) {
			is_visit[yy][xx - 1] = true;
			distance[yy][xx - 1] = distance[yy][xx] + 1;
			qq.push(coord{ xx-1,yy });
		}

		if (xx + 1 <  m && maze[yy][xx + 1] == 1 && !is_visit[yy][xx + 1]) {
			is_visit[yy][xx +1] = true;
			distance[yy][xx +1] = distance[yy][xx] + 1;
			qq.push(coord{ xx+1,yy});
		}

		if (yy - 1 >= 0 && maze[yy-1][xx] == 1 && !is_visit[yy-1][xx]) {
			is_visit[yy-1][xx] = true;
			distance[yy-1][xx] = distance[yy][xx] + 1;
			qq.push(coord{ xx,yy - 1 });
		}

		if (yy +1 < n && maze[yy+1][xx] == 1 && !is_visit[yy+1][xx]) {
			is_visit[yy+1][xx] = true;
			distance[yy+1][xx] = distance[yy][xx] + 1;
			qq.push(coord{ xx,yy + 1 });
		}

	}



}


int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int N, M, tmp1;
	string tmp2;
	cin >> N >> M;
	vector<vector<int>> maze(N, vector<int>(M, 0));
	vector<vector<int>> distance(N, vector<int>(M, -1));
	vector<vector<bool>> is_visit(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		cin >> tmp2;

		for (int j = 0; j <M; j++) {
			tmp1 = tmp2[j] - '0';
			maze[i][j] = tmp1;
		}
	}

	bfs(maze, distance, is_visit);
	cout << distance[N - 1][M - 1];


	return 0;
}