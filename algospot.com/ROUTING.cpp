#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
const double INf = 987654321;

struct node {
	int to;
	double dis;
};
bool operator < (const node& a, const node& b) {
	return a.dis > b.dis;
}


int main() {
	
	int test_case;
	scanf_s("%d", &test_case);

	for (int t = 1; t <= test_case; t++) {

		int V, E;


		scanf_s("%d %d", &V, &E);
		
		vector<vector<pair<int,double>>> adj_list(V);
		vector<double> dis(V, INf);
		for (int i = 0; i < E; i++) {
			
			int from,to;
			double w;
			scanf_s("%d %d %lf", &from, &to, &w);
			adj_list[from].push_back(make_pair( to,log2(w) ));

		}

		priority_queue <node> pq;
		dis[0] = 0;
		pq.push(node{ 0,0 });

		while (!pq.empty()) {
			node next = pq.top();
			pq.pop();
			if (dis[next.to] < next.dis) continue;
			
			for (auto& n : adj_list[next.to]) {
				if (n.second + dis[next.to] < dis[n.first]) {
					dis[n.first] = n.second + dis[next.to];
					pq.push(node{ n.first,dis[n.first] });
				}
			}

		}
		printf_s("%.10lf\n", pow(2,dis[V-1]));




	}




	return 0;
}