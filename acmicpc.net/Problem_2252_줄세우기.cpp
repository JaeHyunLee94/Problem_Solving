#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INT_MAX 2147483647
using namespace std;




int main() {

	
	int n, m, from, to, tmp;
	cin >> n >> m;
	queue <int> vertex;

	vector<int> incoming(n + 1,0);
	vector <bool> is_processed(n + 1, false);
	vector<vector<int>> adj_list(n + 1);

	for (int i = 0; i < m; i++) {

		scanf_s("%d %d", &from, &to);
		incoming[to]++;

		adj_list[from].push_back(to);

	}

	for (int i = 1; i < n + 1;i++) {
		if (!incoming[i]) vertex.push(i);

	}

	while (!vertex.empty()) {

		tmp = vertex.front();
		vertex.pop();

		for (auto& n : adj_list[tmp]) {
			incoming[n]--;
			if (incoming[n] == 0) vertex.push(n);
		}
		is_processed[tmp] = true;
		printf_s("%d ", tmp);

		


	} 


	system("pause");
	return 0;
}