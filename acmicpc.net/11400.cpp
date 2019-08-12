#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int cnt = 1;
int find_cutvertex(const vector<vector<int>>& adj_list, vector <int>& is_visit, vector<pair<int,int>>& cut_vertex,int p, int here) {

	is_visit[here] = cnt++;

	int ret = is_visit[here];
	for (auto& n : adj_list[here]) {
		if (n == p) continue;
		if (!is_visit[n]) {
	
			int child = find_cutvertex(adj_list, is_visit, cut_vertex, here,n);
			ret = min(ret, child);
			if (child > is_visit[here]) cut_vertex.push_back(make_pair(here,n));
		}
		else ret = min(ret, is_visit[n]);

	}




	return ret;


}




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	vector<vector<int>> adj_list(V + 1);
	vector<pair<int,int>> cut_vertex;
	vector<int> is_visited(V + 1, 0);
	for (int i = 0; i < E; i++) {
		int from, to;
		cin >> from >> to;
		adj_list[to].push_back(from);
		adj_list[from].push_back(to);




	}

	for (int i = 1; i <= V; i++) {
		if (!is_visited[i]) find_cutvertex(adj_list, is_visited, cut_vertex, 0,i);
	}
	for (auto& n : cut_vertex) if (n.first > n.second) swap(n.first, n.second);
	sort(cut_vertex.begin(), cut_vertex.end());
	cut_vertex.erase(unique(cut_vertex.begin(), cut_vertex.end()), cut_vertex.end());

	cout << cut_vertex.size() << '\n';
	for (auto& n : cut_vertex) cout << n.first<< " "<<n.second << " "<<'\n';




	return 0;
}
