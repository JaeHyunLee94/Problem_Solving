#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> table(n, vector<int>(10001, 0));
	vector<pair<int, int>> arr(n,pair<int,int>(0,0));
	for (int i = 0; i < n; i++) {
		int byte;
		cin >> byte;
		arr[i].first = byte;
	}
	for (int i = 0; i < n; i++) {
		int cost;
		cin >> cost;
		arr[i].second = cost;
	}
	table[0][0] = (arr[0].second == 0 ? arr[0].first : 0);
	for (int i = 1; i < n; i++) {
		if (arr[i].second == 0) {
			table[i][0] = table[i - 1][0] + arr[i].first;
		}
		else table[i][0] = table[i - 1][0];

	}
	for (int i = 0; i < 10000; i++) {
		if (arr[0].second > i) {
			table[0][i] = 0;
		}
		else table[0][i] = arr[0].first;

	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < 10000; j++) {
			
			if (arr[i].second > j) {
				table[i][j] = table[i-1][j];
			}
			else {
				table[i][j] = max(table[i-1][j], table[i - 1][j - arr[i].second] +arr[i].first );
			}


		}
	}

	int ans = 0;

	for (int i = 0; i < 10000; i++) {
		if (table[n - 1][i] >= m) {
			ans = i;
			break;
		}
	}
	cout << ans;



	return 0;
}
