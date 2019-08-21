#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


using namespace std;

int bfs(const vector<vector<int>>& graph, int now) {

	vector<int> is_visit(graph.size(), -1);
	queue<int> qq;
	is_visit[now] = 1;
	qq.push(now);
	int max_f = 0;
	while (!qq.empty()) {

		int next = qq.front();
		qq.pop();
		if (is_visit[next] >= 4) break;
		max_f++;
		for (int i = 0; i < graph.size(); i++) {
			if (is_visit[i] == -1 && graph[next][i] == 1) {
				
				is_visit[i] = is_visit[next] + 1;
				qq.push(i);
			}
		}

	}
	return max_f;

}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> graph(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			if (tmp[j] == 'Y') {
				graph[i][j] = 1;
			}

		}
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		int n_b = bfs(graph, i);
		if (max < n_b) {
			max = n_b;
		}
	}

	cout <<max-1;

	return 0;
}