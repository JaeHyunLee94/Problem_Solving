#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>


using namespace std;

struct node {
	int ver;
	int dis;
};
bool operator < (const node& a, const node& b) {
	return a.dis > b.dis;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	int from, to, w;
	cin >> n >> m >> k ;

	vector<vector<pair<int, int>>> adj(n+1);
	
	priority_queue<node> pq;
	vector<priority_queue<int>>dis_order(n+1);
	
	dis_order[1].push(0);
	

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> w;
		adj[from].push_back(make_pair(to, w));
	}

	pq.push(node{ 1,0 });

	while (!pq.empty()) {
		node next = pq.top();
		pq.pop();
		

		for (auto& n : adj[next.ver]) {
			if (dis_order[n.first].size() < k) {

				dis_order[n.first].push(next.dis + n.second);
				pq.push(node{ n.first,  next.dis + n.second });
			}

			else if (dis_order[n.first].top() > next.dis + n.second) {
				dis_order[n.first].pop();
				dis_order[n.first].push(next.dis + n.second);
				pq.push(node{ n.first, next.dis + n.second });
			}
		
			
			
		}



	}

	for (int i = 1; i <= n; i++) {
		if (dis_order[i].size() < k) cout << -1 << '\n';
		else cout << dis_order[i].top() << '\n';
			
		
	}





	


	system("pause");




	return 0;
}