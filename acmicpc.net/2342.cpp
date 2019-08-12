#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INFN 987654321

using namespace std;



int cost(int from, int to) {
	if (from == 0) return 2;
	else if (from == to) return 1;
	else if (abs(from - to) == 2) return 4;
	else if (from == 4 && to == 1) return 3;
	else if (from == 1 && to == 4) return 3;
	else if ( abs(from-to)==1) return 3;
	else return INFN;


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> table;
	table.push_back(INFN);
	int tmp;
	cin >> tmp;
	while (tmp) {
		table.push_back(tmp);
		cin >> tmp;
	}
	int N = table.size()-1;

	vector<vector<vector<int>>> DP(N+1, vector<vector<int>>(5, vector<int>(5, INFN)));
	DP[0][0][0] = 0;
	for (int i = 1; i <= N; i++) {

		for (int l = 0; l < 5; l++) {
			for (int r = 0; r < 5; r++) {

				if (table[i]!=r)	DP[i][table[i]][r] = min(DP[i][table[i]][r], DP[i - 1][(l + 1) % 5][r] + cost((l + 1) % 5, table[i]));
			
				if(table[i]!=l )	DP[i][l][table[i]] = min(DP[i][l][table[i]], DP[i - 1][l][(r + 1) % 5] + cost((r + 1) % 5, table[i]));
				


			}
		}
	}
	int ans = INFN;
	for (int l = 0; l < 5; l++) {
		for (int r = 0; r < 5; r++) {

			if ((l==table[N] || r==table[N]) && ans>DP[N][l][r]) ans = DP[N][l][r];
		}
	}

	cout << ans;


	return 0;
}