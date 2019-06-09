#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#define INT_MAX 2147483647
using namespace std;


struct node {
	int ver;
	int dis;

};

bool operator < (const node& a, const node& b) {
	return a.dis > b.dis;
}






int main() {
	
	int ver_num, edge_num, start_ver;
	int f_v, s_v, w;
	node x;

	cin >> ver_num >> edge_num >> start_ver;

	vector <int> shortest_dis(ver_num + 1,INT_MAX);
	vector <bool> is_visit(ver_num + 1, false);
	vector <vector<pair<int,int>>> adj_list(ver_num + 1);

	priority_queue <node> pq;

	for (int i = 0; i < edge_num ; i++) {
		scanf_s("%d %d %d", &f_v, &s_v, &w);
		adj_list[f_v].push_back(make_pair(s_v, w));
	}

	shortest_dis[start_ver] = 0;
	pq.push(node{ start_ver,0 });

	while (!pq.empty()) {

		x = pq.top();
		pq.pop();
		if (is_visit[x.ver]) continue;

		is_visit[x.ver] = true;

		for (auto& n : adj_list[x.ver]) {
			if (is_visit[n.first]) continue;
			
			if (shortest_dis[x.ver] + n.second <= shortest_dis[n.first]) {
				shortest_dis[n.first] = shortest_dis[x.ver] + n.second;
				pq.push(node{ n.first,shortest_dis[n.first] });
			}
			}


		}


	for (int i = 1; i < ver_num + 1; i++) {

		if (shortest_dis[i] == INT_MAX) printf_s("INF\n");
		else printf_s("%d\n",shortest_dis[i]);
	}
	
	
	



 
	
	
	
	system("pause");
	return 0;
}