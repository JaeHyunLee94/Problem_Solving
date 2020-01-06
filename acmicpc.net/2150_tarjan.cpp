#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

int discover_num = 0;
stack<int> st;


int scc(int here,vector<vector<int>>& adj_list,vector<int>& discover,vector<int>& sccid,vector<vector<int>>& ans) {

	int ret = discover[here] = discover_num++;
	st.push(here);

	for (auto& n : adj_list[here]) {
		if (discover[n] == -1) {
			ret = min(ret, scc(n, adj_list, discover,sccid,ans));
		}
		else if (sccid[n] == -1) {
			ret = min(ret, discover[n]);
		}
	}
	
	if (ret == discover[here]) {
		vector<int> tmp;
		while (1) {
			int t = st.top();
			st.pop();
			tmp.push_back(t);
			sccid[t] = 1;
			if (t == here) break;
		}
		ans.push_back(tmp);
	}
	return ret;

}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);



	int V, E;

	cin >> V >> E;

	vector<vector<int>> adj_list(V + 1);
	vector<vector<int>> ans;
	vector<int> discover(V + 1, -1);
	vector<int> sccid(V + 1, -1);
	

	for (int i = 0; i < E; i++) {
		int from, to;

		cin >> from >> to;

		adj_list[from].push_back(to);
	}
	

	for (int i = 1; i < V + 1; i++) {
		if (discover[i] == -1) scc(i, adj_list, discover, sccid,ans);
	}
	
	
	for (int i = 0; i < ans.size(); i++) {
		sort(ans[i].begin(), ans[i].end());
	}
	sort(ans.begin(),ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		for (auto& n : ans[i]) cout << n << ' ';
		cout << -1 << '\n';
	}


	return 0;
}