#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;



struct node {
	int to;
	int w;
};

void bfs(const vector<vector<node>>& tree, vector<int>& depth, vector<vector<int>>& parent, vector<vector<int>>& maxdis, vector<vector<int>>& mindis) {

	depth[1] = 1;
	queue <int> q;
	q.push(1);
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		for (auto& n : tree[next]) {
			if (!depth[n.to]) {
				depth[n.to] = depth[next] + 1;
				parent[0][n.to] = next;
				maxdis[0][n.to] = n.w;
				mindis[0][n.to] = n.w;
				q.push(n.to);
			}
		}
	}


}

int LCA(const vector<vector<node>>& tree, vector<int>& depth, vector<vector<int>>& parent, vector<vector<int>>& min_dis, vector<vector<int>>& max_dis, int a, int b, int& minval, int& maxval) {
	int first, second;
	first = (depth[a] > depth[b] ? a : b);
	second = (depth[a] > depth[b] ? b : a);
	while (depth[first] != depth[second]) {
		int diff = depth[first] - depth[second];
		int u = log2(diff);
		minval = min(min_dis[u][first],minval);
		maxval = max(max_dis[u][first],maxval);
		first = parent[u][first];

	}
	if (first == second) return first;
	else {

		while (first != second) {
			int index = 0;
			for (int i = 0; i < parent.size(); i++) if (parent[i][first] == parent[i][second]) {
				index = i - 1;
				break;
			}
			if (index == -1) {
				minval = min(minval, min(min_dis[0][first], min_dis[0][second]));
				maxval = max(maxval, max(max_dis[0][first], max_dis[0][second]));
				first = parent[0][first];
				second = parent[0][second];
			}
			else {
				minval = min(minval, min(min_dis[index][first], min_dis[index][second]));
				maxval = max(maxval, max(max_dis[index][first], max_dis[index][second]));
				first = parent[index][first];
				second = parent[index][second];

			}
		}
	}
	return first;

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, K;
	cin >> N;
	vector<vector<node>> tree_list(N + 1);
	vector<int> depth(N + 1, 0);
	int max_level = log2(N) + 1;
	vector<vector<int>> parent(max_level, vector<int>(N + 1, 0));
	vector<vector<int>> max_dis(max_level, vector<int>(N + 1, 0));
	vector<vector<int>> min_dis(max_level, vector<int>(N + 1, 2147483647));
	for (int i = 0; i < N - 1; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		tree_list[from].push_back(node{ to,w });
		tree_list[to].push_back(node{ from,w });
	}

	bfs(tree_list, depth, parent, max_dis, min_dis);

	for (int i = 1; i < parent.size(); i++) {
		for (int j = 1; j < parent[0].size(); j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			min_dis[i][j] = min(min_dis[i - 1][parent[i - 1][j]], min_dis[i - 1][j]);
			max_dis[i][j] = max(max_dis[i - 1][parent[i - 1][j]], max_dis[i - 1][j]);
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {

		int from, to, minval = 2147483647, maxval = 0;
		cin >> from >> to;
		LCA(tree_list, depth, parent, min_dis, max_dis, from, to, minval, maxval);
		cout << minval << " " << maxval << '\n';
	}



	return 0;
}
/*
10
1 2 10
2 3 20
3 4 30
4 5 40
1 6 50
6 7 60
7 8 70
8 9 80
9 10 90
*/