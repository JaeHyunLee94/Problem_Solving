#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E;


	cin >> V >> E;

	vector<vector<int>> adj_matrix(V + 1, vector<int>(V + 1, 999999999));

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj_matrix[from][to] = min(cost, adj_matrix[from][to]);
	}

	vector<vector<int>> min_dis = adj_matrix;
	for (int i = 1; i <= V; i++) min_dis[i][i] = 0;
	

	for (int k = 1; k <= V; k++) {
		for (int y = 1; y <= V; y++) {
			for (int x = 1; x <= V; x++) {
				min_dis[y][x] = min(min_dis[y][x], min_dis[y][k] + min_dis[k][x]);
			}
		}
	}

	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++) {
			if (min_dis[i][j] == 999999999) cout << 0<<" ";
			else cout << min_dis[i][j] << " ";
			
		}
		cout << '\n';
	}




	return 0;
}