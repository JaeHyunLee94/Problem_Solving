#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int cnt = 1;
int find_cutvertex(const vector<vector<int>>& adj_list, vector <int> &is_visit, vector<int>& cut_vertex,int here, bool isroot) {

	is_visit[here] = cnt++;
	int childnum = 0;
	int ret = is_visit[here];
	for (auto& n : adj_list[here]) {

		if (!is_visit[n]) {
			childnum++;
			int child = find_cutvertex(adj_list, is_visit, cut_vertex, n, false);
			ret = min(ret, child);
			if (!isroot && child >= is_visit[here]) cut_vertex.push_back(here);
		}
		else ret = min(ret, is_visit[n]);
	
	}
	if (isroot && childnum >= 2) cut_vertex.push_back(here);
	


	return ret;


}









int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int V, E;
	cin >> V >> E;
	vector<vector<int>> adj_list(V + 1);
	vector<int> cut_vertex;
	vector<int> is_visited(V + 1, 0);
	for (int i = 0; i < E; i++) {
		int from, to;
		cin >> from >> to;
		adj_list[to].push_back(from);
		adj_list[from].push_back(to);




	}

	for (int i = 1; i <= V; i++) {
		if (!is_visited[i]) find_cutvertex(adj_list, is_visited, cut_vertex, i, true);
	}

	sort(cut_vertex.begin(), cut_vertex.end());
	cut_vertex.erase(unique(cut_vertex.begin(), cut_vertex.end()), cut_vertex.end());

	cout << cut_vertex.size() << '\n';
	for (auto& n : cut_vertex) cout << n << " ";




	return 0;
}
