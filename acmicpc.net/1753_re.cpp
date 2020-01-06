#include <iostream>
#include <vector>
#include <queue>



using namespace std;


struct node {
	int to;
	int w;
};

struct short_dis {
	int v_num;
	int dis;
};
int INF = 999999;

bool operator <(const short_dis& a,const short_dis& b) {
	return a.dis > b.dis;
}


void dijkstra(vector<vector<node>>& adj_list, vector<int>& dis,int src) {
	int V = adj_list.size() - 1;


	vector<int> is_visit(V + 1, 0);
	dis[src] = 0;
	priority_queue<short_dis> pq;
	pq.push(short_dis{ src,0 });

	while (!pq.empty()) {

		auto next = pq.top();
		pq.pop();

		if (is_visit[next.v_num]) continue;
		is_visit[next.v_num] = 1;

		for (auto& n : adj_list[next.v_num]) {
			if (!is_visit[n.to] && dis[n.to] > dis[next.v_num] + n.w) {
				pq.push(short_dis{ n.to,dis[next.v_num] + n.w });
				dis[n.to] = dis[next.v_num] + n.w;
			}
		}


	}


}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, src;

	cin >> V >> E >> src;

	vector<vector<node>> adj_list(V+1);
	vector<int> dis(V + 1, INF);

	for (int i = 0; i < E; i++) {
		int from, to, w;

		cin >> from >> to >> w;
		int is_in = 0;
		for (auto& n : adj_list[from]) {
			if (n.to == to) {
				n.w = min(w, n.w);
				is_in = 1;
				break;
			}
		}
		if (!is_in) adj_list[from].push_back(node{ to,w });

	}

	dijkstra(adj_list, dis,src);

	for (int i = 1; i < V + 1; i++) {
		if (dis[i] == INF) cout << "INF";
		else cout << dis[i];

		cout << '\n';
		
	}


	return 0;
}