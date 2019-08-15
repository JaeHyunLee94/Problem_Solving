#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_way(int n, vector<int>& DP,vector<int>& table) {

	

	if (DP[n] != -1) return DP[n];

	int& ret = DP[n];

	if (n == 1) {
		return ret = table[1];
	}
	if (n == 2) {
		return ret = table[1] + table[2];
	}
	if (n == 3) {
		return ret = max(max(table[1] + table[2], table[2] + table[3]), table[1] + table[3]);
	}

	else return ret= max(max(find_way(n - 1, DP, table), find_way(n - 2, DP, table) + table[n]), find_way(n - 3, DP, table) + table[n] + table[n - 1]);

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	vector<int> table(N+1, 0);
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;

		table[i] = tmp;
	}
	vector<int> DP(N+1, -1);

	cout << find_way(N, DP, table);




	return 0;
}