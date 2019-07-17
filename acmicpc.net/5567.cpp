#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int V, E;
	int from, to;
	cin >> V >> E;
	vector<vector<int>> adj_list(V + 1);
	vector<int> dis(V + 1, 99999);
	queue<int> qq;
	

	for (int i = 0; i < E; i++) {
		cin >> from >> to;
		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}

	int cnt = 0;
	
	qq.push(1);
	dis[1] = 0;
	while (!qq.empty()) {
		int next = qq.front();
		qq.pop();
		if (dis[next] == 99999) continue;
		if (dis[next] > 2) break;
		for (auto& n : adj_list[next]) {
			if (dis[n] == 99999) {
				qq.push(n);
				dis[n] = dis[next] + 1;
			}
		}

	}
	
	for (int i = 1; i <= V; i++) {
		if (dis[i] <= 2) cnt++;
	}

	cout << cnt-1;



	return 0;
}