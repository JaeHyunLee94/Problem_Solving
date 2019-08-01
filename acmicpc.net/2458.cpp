#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, from, to, ans=0;
	cin >> V >> E;

	vector<vector<int>> adj_mat(V+1 ,vector<int>(V+1,0));
	vector<vector<int>> inv_adj_mat(V+1, vector<int>(V+1, 0));
	
	for (int i = 0; i < E; i++) {
		cin >> from >> to;
		adj_mat[from][to] = 1;
		inv_adj_mat[to][from] = 1;
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				adj_mat[i][j] = max(adj_mat[i][j], adj_mat[i][k] * adj_mat[k][j]);
				inv_adj_mat[i][j] = max(inv_adj_mat[i][j], inv_adj_mat[i][k] * inv_adj_mat[k][j]);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		int sum = 0;
		for (int j = 1; j <= V; j++) {
			if (adj_mat[i][j] == 1) sum++;
			if (inv_adj_mat[i][j] == 1) sum++;
		}
		if (sum == V - 1) ans++;
	}

	cout << ans;



	system("pause");




	return 0;
}