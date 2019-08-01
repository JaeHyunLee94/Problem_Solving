#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>


using namespace std;

struct node {
	int from;
	int to;
	int w;
};


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	int from, to, w;
	int is_cycle = 0;
	cin >> V >> E;


	vector<int> dis(V + 1,987654321);
	vector<node> edge(E);

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> w;
		edge[i] = node{ from , to ,w };
	}
	dis[1] = 0;
	for (int i = 1; i <= V - 1; i++) {

		for (auto& n : edge) if (dis[n.from] + n.w < dis[n.to] && dis[n.from]!= 987654321)  dis[n.to] = dis[n.from] + n.w;

		
	}

	vector<int> check(dis);
	for (auto& n :edge) if (check[n.from] + n.w < check[n.to] && check[n.from] != 987654321)  check[n.to] = check[n.from] + n.w;
	for (int i = 1; i <= V; i++) {
		if (dis[i] != check[i]) {
			is_cycle = 1;
			break;
		}
	}


	if (is_cycle) cout << -1 << '\n';
	else {
		for (int i = 2; i <= V; i++) cout << (dis[i]!=987654321 ? dis[i] : -1 ) << '\n';

	}


	system("pause");




	return 0;
}