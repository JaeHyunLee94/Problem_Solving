#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int find(int u,vector<int>& parent) {
	
	if (u == parent[u]) return u;

	return parent[u] = find(parent[u], parent);


}

void union_f(int u, int v,vector<int>& parent) {
	
	int u1 = find(u, parent);
	int v1 = find(v, parent);
	

	if (u1 == v1) return;

	parent[v] = u;


}

struct node {
	int from;
	int to;
	int w;
};

bool operator < (const node& a, const node& b) {
	return a.w < b.w;
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);


	int V, E;
	cin >> V >> E;
	long long ans = 0;
	int iter = 0;
	int i = 0;

	vector<node> edge_list;
	vector<int> parent(V + 1, 0);
	

	for (int i = 0; i < V + 1; i++) {
		parent[i] = i;
	}


	for (int i = 0; i < E; i++) {
		int from, to, c;

		cin >> from >> to >> c;
		edge_list.push_back(node{ from,to,c });
	}
	sort(edge_list.begin(), edge_list.end());
	while (iter < V - 2) {
		int a = edge_list[i].from;
		int b = edge_list[i].to;
		int c = edge_list[i].w;
		if (find(a, parent) != find(b, parent)) {
			union_f(a, b, parent);
			ans += c;
			iter++;
		}

		i++;
	}


	cout << ans;


	return 0;
}