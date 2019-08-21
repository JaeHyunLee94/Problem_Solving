#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

const long long INf = 92147483648;


struct node {
	long long to;
	long long dis;
};

bool operator < (const node& a, const node& b) {
	return a.dis > b.dis;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int V, E, N, M;
		cin >> V >> E >> N >> M;
		vector<vector<pair<long long, long long>>> adj_list(V + 1);
		vector<long long> dis(V + 1, INf);
		vector<long long> fire_spot(N);
		vector<long long> fire_station(M);
		for (int i = 0; i < E; i++) {
			long long from, to, w;
			cin >> from >> to >> w;
			adj_list[from].push_back(make_pair(to, w));
			adj_list[to].push_back(make_pair(from, w));

		}
		for (int i = 0; i < N; i++) {
			long long tmp;
			cin >> tmp;
			fire_spot[i] = tmp;
		}
		for (int i = 0; i < M; i++) {
			long long tmp;
			cin >> tmp;
			fire_station[i] = tmp;
		}
		int source = fire_station[0];
		for (int i = 1; i < M; i++) {
			adj_list[source].push_back(make_pair(fire_station[i], 0));
		}
		priority_queue <node> pq;
		dis[source] = 0;
		pq.push(node{ source,0 });
		while (!pq.empty()) {
			node next = pq.top();
			pq.pop();
			if (dis[next.to] < next.dis) continue;

			for (auto& n : adj_list[next.to]) {
				if (dis[n.first] > dis[next.to] + n.second) {
					dis[n.first] = dis[next.to] + n.second;
					pq.push(node{ n.first,dis[n.first] });
				}
			}
		}
		long long ans = 0;

		for (int i = 0; i < N; i++) {
			ans += dis[fire_spot[i]];
		}

		cout << ans << '\n';

	}




	return 0;
}

