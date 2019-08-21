#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;


void init_parent(vector<vector<int>>& parent, const vector<vector<int>>& tree,int max_level) {
	int N = tree.size();
	for (int k = 1; k < max_level; k++) {
		for (int i = 1; i < N; i++) {
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	}

}


int LCA(int a, int b, const vector<vector<int>>& tree, const vector<vector<int>>& parent,const vector<int>& depth) {
	

	if (depth[a] < depth[b]) swap(a, b);
	
	while (depth[a] != depth[b]) {
		int diff = depth[a] - depth[b];
		a = parent[(int)(log2(diff))][a];
	}

	if (a == b) return a;

	int skip = 0;
	for (int i = 0; i < parent.size(); i++) {
		if (parent[i][a] == parent[i][b]) {
			skip = i - 1;
			break;
		}
	}
	if (skip == -1) return parent[0][a];
	else return LCA(parent[skip][a], parent[skip][b], tree, parent, depth);


}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> tree(N+1);
	vector<vector<int>> graph(N + 1);
	int max_level = (int)(log2(N+1) + 1);

	vector<vector<int>> parent2n(max_level, vector<int>(N+1, 0));
	vector<int> depth(N + 1, 0);
	depth[1] = 1;

	for (int i = 1; i <= N-1; i++) {
		int from, to;
		cin >> from >> to;		
		graph[from].push_back(to);
		graph[to].push_back(from);
		
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		for (auto& n : graph[next]) {
			if (!depth[n]) {
				tree[next].push_back(n);
				depth[n] = depth[next] + 1;
				parent2n[0][n] = next;
				q.push(n);
			}
		}
	}
	
	init_parent(parent2n, tree,max_level);
	
	int  M;
	

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		cout << LCA(a, b, tree, parent2n, depth) << '\n';

	}




	return 0;
}
/*
17
1 2
2 3
4 3
5 4
6 5
6 7
7 8
9 10
10 11
11 12
12 13
13 14
14 15
8 9
15 16
17 16
*/