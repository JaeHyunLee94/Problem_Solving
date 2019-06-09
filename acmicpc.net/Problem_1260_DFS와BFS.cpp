#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& first, const pair<int, int>& second) {
	return first.first < second.first;
}

void print_bfs(vector<list<pair<int, int>>>& adj_list, int start_v, int* is_visit) {
	queue<int> bfs_q;

	bfs_q.push(start_v);
	is_visit[start_v] = 1;
	while (!bfs_q.empty()) {
		int num = bfs_q.front();
		bfs_q.pop();
		cout << num << " ";
		

		for (auto& n : adj_list[num]) {
			if (n.second >= 1 && is_visit[n.first] == 0) {
				bfs_q.push(n.first);
				is_visit[n.first] = 1;
				n.second--;
				for (auto& m : adj_list[n.first]) {
					if (m.first == num) {
						m.second--;
						break;
					}
				}

			}
		}


	}




}


void print_dfs( vector<list<pair<int,int>>>& adj_list,int start_v, int* is_visit) {
	cout << start_v <<" ";
	is_visit[start_v] = 1;

	for (auto& n : adj_list[start_v]) {
		if (n.second >= 1 && is_visit[n.first]==0) {
			is_visit[n.first] = 1;
			n.second--;
			for (auto& m : adj_list[n.first]) {
				if (m.first == start_v) {
					m.second--;
					break;
				}
			}
			print_dfs(adj_list, n.first, is_visit);

		}

	}


}

void insert_val(vector< list<pair<int, int>> >&i_e, int v1, int v2) {
	int flag = 0;
	for (auto&n : i_e[v1]) {
		if (n.first == v2) {
			n.second++;
			flag = 1;

			break;
		}
	}
	if (flag == 0) i_e[v1].push_back(make_pair(v2,1));
	flag = 0;

	for (auto& n : i_e[v2]) {
		if (n.first == v1) {
			n.second++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) i_e[v2].push_back(make_pair(v1, 1));


}









int main() {
	
	int v_num, e_num, start_enum;

	int is_visit_dfs[1005] = { 0 };
	int is_visit_bfs[1005] = { 0 };
	cin >> v_num;
	cin >> e_num;
	cin >> start_enum;

	vector<list<pair<int,int>>> adj_list_dfs(1005);
	vector<list<pair<int, int>>> adj_list_bfs(1005);

	int v1, v2;
	for (int i = 0; i < e_num; i++) {
		cin >> v1;
		cin >> v2;
		insert_val(adj_list_dfs, v1, v2);

	}
	for (auto& n : adj_list_dfs) {
		n.sort(compare);
	}
	adj_list_bfs = adj_list_dfs;
	print_dfs(adj_list_dfs, start_enum, is_visit_dfs);
	cout << endl;
	print_bfs(adj_list_bfs, start_enum, is_visit_bfs);







	
	//system("pause");
	return 0;
}