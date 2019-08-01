#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

struct node {
	int ver;
	int dis;
};
bool operator < (const node& a, const node& b) {
	return a.dis > b.dis;
}

vector<vector<pair<int,int>>> invert(const vector<vector<pair<int, int>>>& adj) {
	int size = adj.size();
	vector<vector<pair<int, int>>> inv(size);
	for (int i = 0; i < size;i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			inv[adj[i][j].first].push_back(make_pair(i, adj[i][j].second));
		}
	}
	return inv;
}

void delete_edge(vector<vector<pair<int, int>>>& adj, int s, int d) {
	vector<pair<int, int>> ::iterator iter = adj[s].begin();

	while (iter != adj[s].end()) {
		if (iter->first == d) iter = adj[s].erase(iter);
		else iter++;
	}


}

int dijkstra_del(vector<vector<pair<int, int>>>& adj,int S, int D){
	int V = adj.size();
	int ret = 0;
	vector<int> dis(V, 2147483647);// 수정할것
	vector<int> is_visit(V, 0);
	

	priority_queue<node> pq;

	dis[S] = 0;
	
	pq.push(node{ S,0 });
	while (!pq.empty()) {
		node next = pq.top();
		pq.pop();
		if (is_visit[next.ver]) continue;

		is_visit[next.ver] = 1;
		for (auto& n : adj[next.ver]) {
			if (dis[n.first] >= dis[next.ver] + n.second) {
				
				dis[n.first] =dis[next.ver] + n.second;
				pq.push(node{ n.first, dis[n.first] });
			}
		}

	}
	ret = dis[D];

	vector<vector<pair<int, int>>> inv = invert(adj);
	queue<int> qq;
	qq.push(D);
	while (!qq.empty()) {
		int next = qq.front();
		qq.pop();

		for (auto& n : inv[next]) {
			if (dis[n.first] == dis[next] - n.second) {
				qq.push(n.first);
				delete_edge(adj, n.first, next);
			}
		}

	}
	
	return ret;
	
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, S, D;
	cin >> V >> E;

	while (!(V==0 && E==0)) {
		cin >> S >> D;
		vector<vector<pair<int, int>>> adj(V);
		for (int i = 0; i < E; i++) {
			int from, to, w;
			cin >> from >> to >> w;
			adj[from].push_back(make_pair(to, w));
		}
		dijkstra_del(adj, S, D);
		int s = dijkstra_del(adj, S, D);
		cout << (s != 2147483647 ? s : -1) << '\n';







		cin >> V >> E;
	}





	system("pause");




	return 0;
}