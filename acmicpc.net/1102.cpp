#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
const int INF = 987654321;

int find_tsp(int here,int visit,vector<vector<int>>& TSP, vector<vector<int>>& table) {

	if (TSP[here][visit] != -1) return TSP[here][visit];

	int& ret = TSP[here][visit];
	ret = INF;

	if (visit == (1 << N) - 1) {
		if (table[here][0] == 0) return ret=INF;
		else return ret=table[here][0];
	}

	for (int i = 0; i < N; i++) {
		if (!(visit & (1 << i)) && table[here][i] != 0) {
			ret = min(ret, find_tsp(i, visit|(1<<i), TSP, table) + table[here][i]);
		}
	}

	
	return ret;

}




int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	vector<vector<int>> table(N, vector<int>(N, 9999));
	vector<vector<int>> TSP(20, vector<int>((1<<N), -1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			table[i][j] = tmp;

		}
	}
	

	cout << find_tsp(0, 1,TSP,table);


	return 0;
}