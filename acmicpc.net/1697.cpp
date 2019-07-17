#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<vector<int>> adj_list(100001);
	queue <int> qq;
	vector<int> dis(100001, 2147483647);
	

	for (int i = 0; i < 100001; i++) {
		if (i - 1 >= 0) adj_list[i].push_back(i - 1);
		if ( i + 1 < 100001) adj_list[i].push_back(i + 1);
		if (2*i< 100001 && i!=0) adj_list[i].push_back(2*i);
	}
	dis[N] = 0;
	qq.push(N);
	bool is_find = false;
	while (!qq.empty()) {
		int next = qq.front();
		qq.pop();
		for (auto& n : adj_list[next]) {
			if (dis[n] == 2147483647) {
				dis[n] = dis[next] + 1;
				qq.push(n);
				if (n == K) {
					is_find = true;
					break;
				}
			}
		}
		if (is_find) break;
	}

	cout << dis[K];



	return 0;
}