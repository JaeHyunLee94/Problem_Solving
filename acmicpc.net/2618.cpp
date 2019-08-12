#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int N, W;

const int INf = 987654321;


int minimun_ij(int  i, int j, vector<vector<int>>& DP, vector<pair<int, int>>& table) {

	if (DP[i][j] != -1) return DP[i][j];
	int& ret = DP[i][j];
	ret = INf;
	int k = max(i, j);
	if (k == W+1) return ret = 0;

	int dis1 = abs(table[k + 1].first - table[i].first) + abs(table[k + 1].second - table[i].second);
	int dis2 = abs(table[k + 1].first - table[j].first) + abs(table[k + 1].second - table[j].second);

	int min_ij1 = minimun_ij(k + 1, j, DP, table);
	int min_ij2 = minimun_ij(i, k+1, DP, table);

	return ret = min(min_ij1 + dis1, min_ij2 + dis2);
	

	
}

vector<int> v;
void tracing(int i, int j,vector<vector<int>>& DP, vector<pair<int,int>>& table) {
	if (i == W + 1 || j == W + 1) return;

	int k = max(i, j);
	int a1 = DP[k + 1][j];
	int a2 = DP[i][k+1];
	int dis1 = abs(table[k + 1].first - table[i].first) + abs(table[k + 1].second - table[i].second);
	int dis2 = abs(table[k + 1].first - table[j].first) + abs(table[k + 1].second - table[j].second);

	if (a1 + dis1 == DP[i][j]) {
		v.push_back(1);
		tracing(k + 1, j, DP, table);
	}
	else {
		v.push_back(2);
		tracing(i, k + 1, DP, table);

	}

	



}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> W;

	vector<vector<int>> DP(W+2, vector<int>(W+2, -1));

	vector<pair<int,int>> case_arr(W+2,make_pair(-1,-1));

	case_arr[0] = make_pair(1, 1);
	case_arr[1] = make_pair(N, N);
	
	for (int i = 2; i < W+2; i++) {
		int x, y;
		cin >> x >> y;
		case_arr[i].first = x;
		case_arr[i].second = y;
	}


	cout << minimun_ij(0, 1, DP, case_arr) << '\n';
	tracing(0, 1, DP, case_arr);

	for (auto& n : v) cout << n << '\n';


	return 0;
}