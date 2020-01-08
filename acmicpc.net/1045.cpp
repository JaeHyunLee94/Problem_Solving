#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

struct edge {
	int from;
	int to;
	int w;
	int is_selected;
};



int find(vector<int>& parent,int u) {
	if (u == parent[u]) return u;

	return parent[u] = find(parent, parent[u]);
}

void union_f(vector<int>& parent, int u, int v) {
	int p_u = find(parent, u);
	int p_v = find(parent, v);

	if (p_u == p_v) return;
	else {
		parent[p_u] = p_v;
		return;
	}
}


int is_connected(vector<vector<int>>& mat) {
	int size = mat.size();
	vector<int> is_visited(size, 0);

	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int next = q.front();
		q.pop();

		if (is_visited[next]) continue;
		else {
			is_visited[next] = 1;
			for (int i = 0; i < size; i++) {
				if (mat[next][i] == 1 && !is_visited[i]) {
					q.push(i);
				}
			}
		}
	}

	for (int i = 0; i < size; i++) {
		if (!is_visited[i]) return 0;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;

	int priority = 0;
	int edge_count = 0;

	vector<vector<int>> mat(N, vector<int>(N, 0));
	
	vector<int> adj_num(N, 0);
	vector<edge> edg;


	vector<int> parent(N, 0);
	


	for (int i = 0; i < N; i++) {
		parent[i] = i;
		for (int j = 0; j < N; j++) {

			char tmp;
			cin >> tmp;

			if (tmp == 'Y') {
				mat[i][j] = 1;
				if (i < j) {
					edg.push_back(edge{ i,j,priority++,0 });
					edge_count++;
				}
				
			}
		}

	}

	if (is_connected(mat) && edge_count>=M) {

		int num = 0;
		int iter_mst = 0;
		while (num < N - 1) {
			if (find(parent, edg[iter_mst].from) != find(parent, edg[iter_mst].to)) {
				union_f(parent, edg[iter_mst].from, edg[iter_mst].to);
				edg[iter_mst].is_selected = 1;
				adj_num[edg[iter_mst].from]++;
				adj_num[edg[iter_mst].to]++;
				num++;

			}
			iter_mst++;
		}
		int count = 0;
		int iter = 0;
		while (count < M - (N - 1)) {
			if (!edg[iter].is_selected) {
				
				edg[iter].is_selected = 1;
				adj_num[edg[iter].from]++;
				adj_num[edg[iter].to]++;
				count++;

			}
			iter++;

		}

		for (int i = 0; i < N; i++) {
			cout << adj_num[i] << ' ';
		}


	}
	else cout << -1;





	return 0;

}