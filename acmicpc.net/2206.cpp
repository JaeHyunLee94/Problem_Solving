#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int INf = 987654321;

struct node{
	int y, x, is_attack, dis;
};


int bfs(const vector<vector<int>>& matrix) {
	int N = matrix.size();
	int M = matrix[0].size();

	vector<vector<vector<int>>> is_visit(2,vector<vector<int>>(N, vector<int>(M, false)));
	vector<vector<vector<int>>> dis(2,vector<vector<int>>(N, vector<int>(M, INf)));

	queue<node> qq;
	qq.push(node{ 0,0,0,0 });
	dis[0][0][0] = 0;

	while (!qq.empty()) {
		node next_point = qq.front();
		qq.pop();

		if (next_point.is_attack && is_visit[1][next_point.y][next_point.x]) continue;
		else if (!next_point.is_attack && is_visit[0][next_point.y][next_point.x]) continue;

		is_visit[next_point.is_attack][next_point.y][next_point.x] = true;
		dis[next_point.is_attack][next_point.y][next_point.x] =next_point.dis;
		
		if (next_point.x - 1 >= 0 && !is_visit[next_point.is_attack][next_point.y][next_point.x-1]) {
			if (next_point.is_attack && !matrix[next_point.y][next_point.x - 1]) {
				qq.push(node{ next_point.y,next_point.x - 1,1,next_point.dis + 1 });
			}
			else if (!next_point.is_attack && !matrix[next_point.y][next_point.x - 1]) {
				qq.push(node{ next_point.y,next_point.x - 1,0,next_point.dis + 1 });
			}
			else if (!next_point.is_attack && matrix[next_point.y][next_point.x - 1]) {
				qq.push(node{ next_point.y,next_point.x - 1,1,next_point.dis + 1 });
			}
		}
		if (next_point.x + 1 < M && !is_visit[next_point.is_attack][next_point.y][next_point.x + 1]) {
			if (next_point.is_attack && !matrix[next_point.y][next_point.x + 1]) {
				qq.push(node{ next_point.y,next_point.x + 1,1,next_point.dis + 1 });
			}
			else if (!next_point.is_attack && !matrix[next_point.y][next_point.x + 1]) {
				qq.push(node{ next_point.y,next_point.x + 1,0,next_point.dis + 1 });
			}
			else if (!next_point.is_attack && matrix[next_point.y][next_point.x + 1]) {
				qq.push(node{ next_point.y,next_point.x + 1,1,next_point.dis + 1 });
			}

		}
		if (next_point.y + 1 < N && !is_visit[next_point.is_attack][next_point.y+1][next_point.x]) {
			if (next_point.is_attack && !matrix[next_point.y+1][next_point.x]) {
				qq.push(node{ next_point.y+1,next_point.x ,1,next_point.dis + 1 });
			}
			else if (!next_point.is_attack && !matrix[next_point.y+1][next_point.x]) {
				qq.push(node{ next_point.y+1,next_point.x,0,next_point.dis + 1 });
			}
			else if (!next_point.is_attack && matrix[next_point.y+1][next_point.x]) {
				qq.push(node{ next_point.y+1,next_point.x ,1,next_point.dis + 1 });
			}

		}
		if (next_point.y - 1 >= 0 && !is_visit[next_point.is_attack][next_point.y-1][next_point.x]) {
			if (next_point.is_attack && !matrix[next_point.y-1][next_point.x]) {
				qq.push(node{ next_point.y-1,next_point.x ,1,next_point.dis + 1 });
			}
			else if (!next_point.is_attack && !matrix[next_point.y-1][next_point.x ]) {
				qq.push(node{ next_point.y-1,next_point.x ,0,next_point.dis + 1 });
			}
			else if (!next_point.is_attack && matrix[next_point.y-1][next_point.x ]) {
				qq.push(node{ next_point.y-1,next_point.x ,1,next_point.dis + 1 });
			}

		}

	}
	return min(dis[0][N - 1][M - 1],dis[1][N-1][M-1]);


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> matrix(N, vector<int>(M, 0));
	
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			
			matrix[i][j] = tmp[j]-'0';
		}
	}

	int ans = bfs(matrix) + 1;

	cout << (ans == INf+1 ? -1 : ans);


	return 0;
}