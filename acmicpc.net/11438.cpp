#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

void bfs(const vector<vector<int>>& tree, vector<vector<int>>& parent, vector<int>& depth) {


	parent[0][1] = 0;
	depth[1] = 1;
	vector<int> is_visit(tree.size(),0);
	queue <int> ver;
	ver.push(1);
	while (!ver.empty()) {
		int next = ver.front();
		ver.pop();
		if (is_visit[next]) continue;
		is_visit[next] = 1;

		for (auto& n : tree[next]) {
			if (!is_visit[n]) {
				depth[n] = depth[next] + 1;
				parent[0][n] = next;
				ver.push(n);
			}
			
		}


	}
}

int LCA(const vector<vector<int>>& tree, const vector<int>& depth, const vector<vector<int>>& parent,  int a, int b) {
	int first, second;

	if (depth[a] > depth[b]) {
		first = a;
		second = b;
	}
	else {
		first = b;
		second = a;
	}


	while (depth[first] != depth[second]) {
		int diff = depth[first] - depth[second];
		first = parent[(int)(log2((double) diff))][first];
	}


	if (first == second) return first;
	else {
		int next_k = 0;
		for (int k = 0; k <parent.size() ; k++) {
			if (parent[k][first] == parent[k][second]) {
				next_k = k;
				break;
			}
		}
		if (next_k == 0) return parent[0][first];
		else return LCA(tree, depth, parent, parent[next_k - 1][first], parent[next_k - 1][second]);
			
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int N, M;
	int p, c;
	int a, b;
	cin >> N;
	vector<vector<int>> tree(N+1);
	int max_level = (int)(log(N + 1) / log(2))+1 ;
	vector<int> depth(N+1,-1);
	vector<vector<int>> parent(max_level, vector<int>(N+1,0));

	for (int i = 1; i <= N - 1; i++) {
		cin >> p >> c;
		tree[p].push_back(c);
		tree[c].push_back(p);
	}
	bfs(tree, parent, depth);
	for (int k = 1; k < max_level; k++) {
		for (int i = 1; i <= N; i++) {
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << LCA(tree, depth, parent, a, b) << '\n';
	}




	system("pause");

	return 0;
}

