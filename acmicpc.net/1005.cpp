#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>



using namespace std;

struct node {
	int time;
	int in;
	int ee;
};


int main() {

	int test_case = 0;
	int vertex = 0, edge = 0;
	int from = 0, to = 0;
	int time = 0;
	int last = 0;
	cin >> test_case;



	for (int i = 0; i < test_case; i++) {
		scanf("%d %d", &vertex, &edge);

		vector<vector<int>> adj_list(vertex + 1);
		vector<node> node_info(vertex + 1);
		stack <int> st;

		for (int j = 1; j < vertex + 1; j++) {
			scanf("%d", &time);
			node_info[j] = { time,0,0 };
		}

		for (int j = 0; j < edge; j++) {
			scanf("%d %d", &from, &to);
			adj_list[from].push_back(to);
			node_info[to].in++;
		}
		scanf("%d", &last);

		for (int j = 1; j < vertex + 1; j++) {
			if (!node_info[j].in) st.push(j);
		}
		while (!st.empty()) {
			int tmp_ver = st.top();
			st.pop();

			for (auto& n : adj_list[tmp_ver]) {
				node_info[n].in--;
				if (!node_info[n].in) st.push(n);

				if (node_info[tmp_ver].ee + node_info[tmp_ver].time >= node_info[n].ee)
					node_info[n].ee = node_info[tmp_ver].ee + node_info[tmp_ver].time;


			}
		}

		printf("%d\n", node_info[last].time + node_info[last].ee);


	}





	return 0;
}