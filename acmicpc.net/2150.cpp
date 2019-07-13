#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void dfs_here(int here, const vector<vector<int>>& adj_list, vector<int>& is_visit,vector<int>& topological_order) {
	is_visit[here] = true;

	for (auto& n : adj_list[here]) {
		if (!is_visit[n]) dfs_here(n,adj_list,is_visit,topological_order);
	}
	topological_order.push_back(here);
}



void topo_sort( const vector<vector<int>>& adj_list, vector<int>& topological_order) {
	vector<int> is_visit(adj_list.size(),false);
	for (int i = 1; i < adj_list.size(); i++) {
		if(!is_visit[i]) dfs_here(i, adj_list, is_visit, topological_order);
	}
		
	
}

void kosaraju(const vector<vector<int>>& inv_adj, vector<int>& topological_order,vector<vector<int>>& SCC) {
	vector<int> is_visit(inv_adj.size(), false);
	while (!topological_order.empty()) {
		int tmp = topological_order.back();
		topological_order.pop_back();

		if (!is_visit[tmp]) {
			vector<int> scc_part;
			dfs_here(tmp, inv_adj, is_visit, scc_part);
			SCC.push_back(scc_part);
		}

	}

	
}


int main() {



	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	int from, to;
	cin >> V >> E;
	vector<vector<int>> adj_list(V + 1);
	vector<vector<int>> inv_adj_list(V + 1);
	vector<int> topological_order;
	vector<vector<int>> SCC;
	
	for (int i = 0; i < E; i++) {
		cin >> from >> to;
		adj_list[from].push_back(to);
		inv_adj_list[to].push_back(from);
	}

	topo_sort(adj_list, topological_order);
	kosaraju(inv_adj_list, topological_order, SCC);
	for (auto& n : SCC) sort(n.begin(), n.end());

	sort(SCC.begin(), SCC.end());
	cout << SCC.size() << '\n';
	for (auto& n : SCC) {
		for (auto& m : n) cout << m << " ";
		cout << "-1\n";
	}




	return 0;
}