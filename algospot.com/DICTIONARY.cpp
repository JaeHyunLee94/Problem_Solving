#include <iostream>
#include <algorithm>
#include <string>
#include <vector>




using namespace std;


void determine_priority(vector<vector<int>>& adj_list, const vector<string>& table) {

	for (int i = 1; i < table.size(); i++) {

		int j = i - 1;
		for (int k = 0; k < min(table[i].size(), table[j].size()); k++) {

			if (table[j][k] != table[i][k]) {
				adj_list[table[j][k] - 'a'].push_back(table[i][k] - 'a');
				break;
			}


		}


	}

}

void topological_sort_dfs(const vector<vector<int>>& adj_list,int start,vector<int>& stack,vector<bool>& is_visit,bool& is_cycle,vector<bool>& is_finished) {

	if (is_visit[start]) return;

	is_visit[start] = true;

	for (auto& n : adj_list[start]) {
		if (is_visit[n] && !is_finished[n]) is_cycle = true;
		if (!is_visit[n]) topological_sort_dfs(adj_list, n, stack, is_visit,is_cycle,is_finished);
	}

	stack.push_back(start);
	is_finished[start] = true;
	return;

}





int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string tmp;
	int test_case = 0;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int n;
		cin >> n;
		vector<string> table(n);
		vector<vector<int>> adj_list(26);
		vector<int> stack;
		vector<bool> is_visit(26, false);
		vector<bool> is_finished(26, false);
		bool is_cycle = false;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			table[i] = tmp;
		}
		determine_priority(adj_list, table);
		for (int i = 0; i < adj_list.size();i++) {
			topological_sort_dfs(adj_list, i, stack, is_visit, is_cycle, is_finished);
		}

		if (!is_cycle) {
			reverse(stack.begin(), stack.end());
			for (auto& n : stack) cout << (char)(n + 'a');
		}
		else cout << "INVALID HYPOTHESIS";

		cout << "\n";





	}






	return 0;
}