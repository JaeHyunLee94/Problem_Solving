#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int V, E;
		cin >> V >> E;
		vector<vector<int>> adj_list(V + 1);
		for (int i = 0; i < E; i++) {
			int from, to;
			cin >> from >> to;
			adj_list[from].push_back(to);
			adj_list[to].push_back(from);
		}
		cout << V - 1 << '\n';
	}


	

	return 0;
}