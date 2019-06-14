#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INT_MAX 2147483647
using namespace std;

struct node {
	int vertex;
	int dis;
};

bool operator < (const node& a, const node& b) {
	return a.dis > b.dis;
}



int main() {

	int N, M, X;
	cin >> N >> M >> X;
	int from, to, w;

	vector<vector<pair<int, int>>> adj(N + 1);
	vector<vector<pair<int, int>>> inv_adj(N + 1);

	vector<bool> is_visit(N + 1,false);
	vector<bool> inv_is_visit( N + 1,false);

	vector<int> dis_to(N + 1,INT_MAX);
	vector<int> inv_dis_to(N + 1, INT_MAX);

	priority_queue<node> pq;
	priority_queue<node> inv_pq;

	vector<int> max_child(N + 1,0);

	for (int i = 0; i < M; i++) {
		scanf_s("%d %d %d", &from, &to, &w);
		adj[from].push_back(make_pair(to, w));
		inv_adj[to].push_back(make_pair(from, w));
	}

	dis_to[X] = 0;
	inv_dis_to[X] = 0;
	node x;

	pq.push(node{ X,0 });
	while (!pq.empty()) {
		x = pq.top();
		pq.pop();

		if (is_visit[x.vertex]) continue;
		else {

			for (auto& n : adj[x.vertex]) {
				if (!is_visit[n.first] && dis_to[x.vertex] + n.second < dis_to[n.first]) {
					dis_to[n.first] = dis_to[x.vertex] + n.second;
					pq.push(node{ n.first,dis_to[n.first] });
				}
			}

		}


	}

	inv_pq.push(node{ X,0 });
	while (!inv_pq.empty()) {
		x = inv_pq.top();
		inv_pq.pop();

		if (inv_is_visit[x.vertex]) continue;
		else {

			for (auto& n : inv_adj[x.vertex]) {
				if (!inv_is_visit[n.first] && inv_dis_to[x.vertex] + n.second < inv_dis_to[n.first]) {
					inv_dis_to[n.first] = inv_dis_to[x.vertex] + n.second;
					inv_pq.push(node{ n.first,dis_to[n.first] });
				}
			}

		}


	}

	for (int i = 1; i < N + 1; i++) {
		max_child[i] = dis_to[i] + inv_dis_to[i];

	}
	
	cout <<  *max_element(max_child.begin(), max_child.end());



	
	
	
	
	
	
	system("pause");
	return 0;
}