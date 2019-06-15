#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


void DFS(const vector<vector<int>>& adj,  vector<bool> &is_visited,int start) {

	is_visited[start] = true;

	for (auto& n : adj[start]) {
		if (!is_visited[n]) {
			DFS(adj, is_visited, n);
		}
		
		
	}
}



int main() {


	int ver, edge, tmp1, tmp2;

	cin >> ver;
	cin >> edge;


	vector<vector<int>> adj_list(ver + 1);
	vector<bool> is_visited(ver + 1, false);

	
	for (int i = 0; i < edge; i++) {
		scanf_s("%d %d", &tmp1, &tmp2);
		adj_list[tmp1].push_back(tmp2);
		adj_list[tmp2].push_back(tmp1);
	}
	DFS(adj_list, is_visited, 1);

	cout << count(is_visited.begin(), is_visited.end(), true)-1;

		
	system("pause");
	return 0;
}