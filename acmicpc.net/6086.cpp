#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>




using namespace std;

void bfs(vector<vector<int>>& capacity, vector<vector<int>>& flow, vector<int>& parent) {

	int src = 0;
	queue<int> q;
	q.push(src);

	while (!q.empty()) {
		int next = q.front();
		q.pop();

		for (int i = 0; i < 52; i++) {
			if (capacity[next][i] - flow[next][i] > 0 && parent[i] == -1) {
				q.push(i);
				parent[i] = next;
			}
		}
	}


}

int max_flow(vector<vector<int>>& capacity) {

	int ans = 0;

	vector<vector<int>> flow(52, vector<int>(52, 0));

	

	while(1){

		vector<int> parent(52, -1);
		bfs(capacity, flow, parent);
		int index = 50;
		if (parent[50] == -1) break;
		int plus_flow = 99999;
		while (index != 0) {
			if (capacity[parent[index]][index] - flow[parent[index]][index] < plus_flow) {
				plus_flow = capacity[parent[index]][index] - flow[parent[index]][index];
				
		
			}
			index = parent[index];
		}
		ans += plus_flow;
		index = 50;
		while (index != 0) {
			flow[parent[index]][index] += plus_flow;
			flow[index][parent[index]] -= plus_flow;
			index = parent[index];
			
		}
		
		
	}


	return ans;


}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);



	int N;
	cin >> N;

	vector<vector<int>> capacity(52, vector<int>(52, 0));

	
	for (int i = 0; i < N; i++) {
		char from, to;
		int c;
		cin >> from >> to >> c;
		from = (from >= 97) ? 2 * (from - 97)+1 : 2 * (from - 65);
		to = (to >= 97) ? 2 * (to - 97) + 1 : 2 * (to - 65);
		capacity[from][to] += c;
		capacity[to][from] += c;
	}

	cout << max_flow(capacity);

	return 0;
}