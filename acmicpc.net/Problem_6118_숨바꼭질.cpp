#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int vertex;
	int dis;
};

bool operator < (const node& a, const node& b) {
	return a.dis > b.dis;
}

int main() {
	int n, m;
	node tmp;
	cin >> n >> m;
	vector<vector<int>> adj_list(n + 1);
	vector <bool> is_visited(n + 1,false);
	vector<int> dis_to(n + 1,INT_MAX);

	priority_queue<node,vector<node>,less<node>> pq;
	int from, to;

	
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &from, &to);
		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}

	dis_to[1] = 0;
	pq.push(node{ 1,0 });

	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();

		if (is_visited[tmp.vertex]) continue;
		else {
			is_visited[tmp.vertex] = true;
			for (auto& n : adj_list[tmp.vertex]) {
				if (!is_visited[n]&& dis_to[n]>dis_to[tmp.vertex]+1) {
					dis_to[n] = dis_to[tmp.vertex] + 1;
					pq.push(node{ n,dis_to[n] });
				}
			}
		}
	

	}
	int hut = 0;
	int swit = 0;
	int same = 0;

	int max_dis =* max_element(dis_to.begin()+1, dis_to.end());
	for (int i = 1; i < dis_to.size();i++) {
		if (dis_to[i]==max_dis) {
			if (swit == 0) {
				swit = 1;
				hut = i;
				same++;
			}
			else same++;
		}
		
	}

	cout << hut << " " << max_dis << " " << same;


	






	return 0;
}