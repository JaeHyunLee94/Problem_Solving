#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int V, from, time;
	cin >> V;
	vector<int> earlist(V + 1, 0);
	vector<vector<int>> adj_list(V + 1);
	vector<int> in_degree(V + 1,0);
	vector<int> is_visit(V + 1, 0);
	vector<int> the_time(V + 1, 0);
	queue<int> next;

	for (int i = 1; i <= V; i++) {
		cin >> time;
		the_time[i] = time;
		cin >> from;
		while (from != -1) {
			adj_list[from].push_back(i);
			in_degree[i]++;
			cin >> from;
		}

	}

	for (int i = 1; i <= V; i++)
		if (!in_degree[i]) {
		next.push(i);
		earlist[i] = the_time[i];
		}

	while (!next.empty()) {
		int next_ver = next.front();
		next.pop();
		if (is_visit[next_ver]) continue;
		
		is_visit[next_ver] = 1;

		for (auto& n : adj_list[next_ver]) {
			in_degree[n]--;
			if (!in_degree[n]) next.push(n);
			earlist[n] = max(earlist[n], earlist[next_ver] + the_time[n]);
		}
	}
	for (int i = 1; i <= V; i++) cout << earlist[i] << '\n';








	system("pause");




	return 0;
}